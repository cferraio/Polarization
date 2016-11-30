//This macro makes the following plots, in order:
// 1) <Nch> vs nPriVtx for Nch bins 1 - 5
// 2) Ratio of Nch_NoPU / Nch_IntegratedPU
// 3) Same as 1), but all on one plot
// 4) Same as 3), but log scale
// 5) Nch_IntegratedPU - Nch_NoPU vs Nch bin


//this file is the output of polData.C -> same exact code used for the analysis, 
//just with added functionality to plot Nch distros in nPriVtx bins
{TFile f("DataFiles/SetOfCuts11_countTksOfPV/tmpFiles/selEvents_data_Ups.root");
//{TFile f("selEvents_data_Ups.root");

//these means are the Nch mean in the 5 Nch and 25 nPriVtx, 
//with the standard error of mean
Double_t mean[5][25];
Double_t meanerror[5][25];

mean[0][0]=Reco_Onia_CPM0_PU_0->GetMean();
mean[0][1]=Reco_Onia_CPM0_PU_1->GetMean();
mean[0][2]=Reco_Onia_CPM0_PU_2->GetMean();
mean[0][3]=Reco_Onia_CPM0_PU_3->GetMean();
mean[0][4]=Reco_Onia_CPM0_PU_4->GetMean();
mean[0][5]=Reco_Onia_CPM0_PU_5->GetMean();
mean[0][6]=Reco_Onia_CPM0_PU_6->GetMean();
mean[0][7]=Reco_Onia_CPM0_PU_7->GetMean();
mean[0][8]=Reco_Onia_CPM0_PU_8->GetMean();
mean[0][9]=Reco_Onia_CPM0_PU_9->GetMean();
mean[0][10]=Reco_Onia_CPM0_PU_10->GetMean();
mean[0][11]=Reco_Onia_CPM0_PU_11->GetMean();
mean[0][12]=Reco_Onia_CPM0_PU_12->GetMean();
mean[0][13]=Reco_Onia_CPM0_PU_13->GetMean();
mean[0][14]=Reco_Onia_CPM0_PU_14->GetMean();
mean[0][15]=Reco_Onia_CPM0_PU_15->GetMean();
mean[0][16]=Reco_Onia_CPM0_PU_16->GetMean();
mean[0][17]=Reco_Onia_CPM0_PU_17->GetMean();
mean[0][18]=Reco_Onia_CPM0_PU_18->GetMean();
mean[0][19]=Reco_Onia_CPM0_PU_19->GetMean();
mean[0][20]=Reco_Onia_CPM0_PU_20->GetMean();
mean[0][21]=Reco_Onia_CPM0_PU_21->GetMean();
mean[0][22]=Reco_Onia_CPM0_PU_22->GetMean();
mean[0][23]=Reco_Onia_CPM0_PU_23->GetMean();
mean[0][24]=Reco_Onia_CPM0_PU_24->GetMean();

mean[1][0]=Reco_Onia_CPM1_PU_0->GetMean();
mean[1][1]=Reco_Onia_CPM1_PU_1->GetMean();
mean[1][2]=Reco_Onia_CPM1_PU_2->GetMean();
mean[1][3]=Reco_Onia_CPM1_PU_3->GetMean();
mean[1][4]=Reco_Onia_CPM1_PU_4->GetMean();
mean[1][5]=Reco_Onia_CPM1_PU_5->GetMean();
mean[1][6]=Reco_Onia_CPM1_PU_6->GetMean();
mean[1][7]=Reco_Onia_CPM1_PU_7->GetMean();
mean[1][8]=Reco_Onia_CPM1_PU_8->GetMean();
mean[1][9]=Reco_Onia_CPM1_PU_9->GetMean();
mean[1][10]=Reco_Onia_CPM1_PU_10->GetMean();
mean[1][11]=Reco_Onia_CPM1_PU_11->GetMean();
mean[1][12]=Reco_Onia_CPM1_PU_12->GetMean();
mean[1][13]=Reco_Onia_CPM1_PU_13->GetMean();
mean[1][14]=Reco_Onia_CPM1_PU_14->GetMean();
mean[1][15]=Reco_Onia_CPM1_PU_15->GetMean();
mean[1][16]=Reco_Onia_CPM1_PU_16->GetMean();
mean[1][17]=Reco_Onia_CPM1_PU_17->GetMean();
mean[1][18]=Reco_Onia_CPM1_PU_18->GetMean();
mean[1][19]=Reco_Onia_CPM1_PU_19->GetMean();
mean[1][20]=Reco_Onia_CPM1_PU_20->GetMean();
mean[1][21]=Reco_Onia_CPM1_PU_21->GetMean();
mean[1][22]=Reco_Onia_CPM1_PU_22->GetMean();
mean[1][23]=Reco_Onia_CPM1_PU_23->GetMean();
mean[1][24]=Reco_Onia_CPM1_PU_24->GetMean();

mean[2][0]=Reco_Onia_CPM2_PU_0->GetMean();
mean[2][1]=Reco_Onia_CPM2_PU_1->GetMean();
mean[2][2]=Reco_Onia_CPM2_PU_2->GetMean();
mean[2][3]=Reco_Onia_CPM2_PU_3->GetMean();
mean[2][4]=Reco_Onia_CPM2_PU_4->GetMean();
mean[2][5]=Reco_Onia_CPM2_PU_5->GetMean();
mean[2][6]=Reco_Onia_CPM2_PU_6->GetMean();
mean[2][7]=Reco_Onia_CPM2_PU_7->GetMean();
mean[2][8]=Reco_Onia_CPM2_PU_8->GetMean();
mean[2][9]=Reco_Onia_CPM2_PU_9->GetMean();
mean[2][10]=Reco_Onia_CPM2_PU_10->GetMean();
mean[2][11]=Reco_Onia_CPM2_PU_11->GetMean();
mean[2][12]=Reco_Onia_CPM2_PU_12->GetMean();
mean[2][13]=Reco_Onia_CPM2_PU_13->GetMean();
mean[2][14]=Reco_Onia_CPM2_PU_14->GetMean();
mean[2][15]=Reco_Onia_CPM2_PU_15->GetMean();
mean[2][16]=Reco_Onia_CPM2_PU_16->GetMean();
mean[2][17]=Reco_Onia_CPM2_PU_17->GetMean();
mean[2][18]=Reco_Onia_CPM2_PU_18->GetMean();
mean[2][19]=Reco_Onia_CPM2_PU_19->GetMean();
mean[2][20]=Reco_Onia_CPM2_PU_20->GetMean();
mean[2][21]=Reco_Onia_CPM2_PU_21->GetMean();
mean[2][22]=Reco_Onia_CPM2_PU_22->GetMean();
mean[2][23]=Reco_Onia_CPM2_PU_23->GetMean();
mean[2][24]=Reco_Onia_CPM2_PU_24->GetMean();

mean[3][0]=Reco_Onia_CPM3_PU_0->GetMean();
mean[3][1]=Reco_Onia_CPM3_PU_1->GetMean();
mean[3][2]=Reco_Onia_CPM3_PU_2->GetMean();
mean[3][3]=Reco_Onia_CPM3_PU_3->GetMean();
mean[3][4]=Reco_Onia_CPM3_PU_4->GetMean();
mean[3][5]=Reco_Onia_CPM3_PU_5->GetMean();
mean[3][6]=Reco_Onia_CPM3_PU_6->GetMean();
mean[3][7]=Reco_Onia_CPM3_PU_7->GetMean();
mean[3][8]=Reco_Onia_CPM3_PU_8->GetMean();
mean[3][9]=Reco_Onia_CPM3_PU_9->GetMean();
mean[3][10]=Reco_Onia_CPM3_PU_10->GetMean();
mean[3][11]=Reco_Onia_CPM3_PU_11->GetMean();
mean[3][12]=Reco_Onia_CPM3_PU_12->GetMean();
mean[3][13]=Reco_Onia_CPM3_PU_13->GetMean();
mean[3][14]=Reco_Onia_CPM3_PU_14->GetMean();
mean[3][15]=Reco_Onia_CPM3_PU_15->GetMean();
mean[3][16]=Reco_Onia_CPM3_PU_16->GetMean();
mean[3][17]=Reco_Onia_CPM3_PU_17->GetMean();
mean[3][18]=Reco_Onia_CPM3_PU_18->GetMean();
mean[3][19]=Reco_Onia_CPM3_PU_19->GetMean();
mean[3][20]=Reco_Onia_CPM3_PU_20->GetMean();
mean[3][21]=Reco_Onia_CPM3_PU_21->GetMean();
mean[3][22]=Reco_Onia_CPM3_PU_22->GetMean();
mean[3][23]=Reco_Onia_CPM3_PU_23->GetMean();
mean[3][24]=Reco_Onia_CPM3_PU_24->GetMean();

mean[4][0]=Reco_Onia_CPM4_PU_0->GetMean();
mean[4][1]=Reco_Onia_CPM4_PU_1->GetMean();
mean[4][2]=Reco_Onia_CPM4_PU_2->GetMean();
mean[4][3]=Reco_Onia_CPM4_PU_3->GetMean();
mean[4][4]=Reco_Onia_CPM4_PU_4->GetMean();
mean[4][5]=Reco_Onia_CPM4_PU_5->GetMean();
mean[4][6]=Reco_Onia_CPM4_PU_6->GetMean();
mean[4][7]=Reco_Onia_CPM4_PU_7->GetMean();
mean[4][8]=Reco_Onia_CPM4_PU_8->GetMean();
mean[4][9]=Reco_Onia_CPM4_PU_9->GetMean();
mean[4][10]=Reco_Onia_CPM4_PU_10->GetMean();
mean[4][11]=Reco_Onia_CPM4_PU_11->GetMean();
mean[4][12]=Reco_Onia_CPM4_PU_12->GetMean();
mean[4][13]=Reco_Onia_CPM4_PU_13->GetMean();
mean[4][14]=Reco_Onia_CPM4_PU_14->GetMean();
mean[4][15]=Reco_Onia_CPM4_PU_15->GetMean();
mean[4][16]=Reco_Onia_CPM4_PU_16->GetMean();
mean[4][17]=Reco_Onia_CPM4_PU_17->GetMean();
mean[4][18]=Reco_Onia_CPM4_PU_18->GetMean();
mean[4][19]=Reco_Onia_CPM4_PU_19->GetMean();
mean[4][20]=Reco_Onia_CPM4_PU_20->GetMean();
mean[4][21]=Reco_Onia_CPM4_PU_21->GetMean();
mean[4][22]=Reco_Onia_CPM4_PU_22->GetMean();
mean[4][23]=Reco_Onia_CPM4_PU_23->GetMean();
mean[4][24]=Reco_Onia_CPM4_PU_24->GetMean();

meanerror[0][0]=Reco_Onia_CPM0_PU_0->GetMeanError();
meanerror[0][1]=Reco_Onia_CPM0_PU_1->GetMeanError();
meanerror[0][2]=Reco_Onia_CPM0_PU_2->GetMeanError();
meanerror[0][3]=Reco_Onia_CPM0_PU_3->GetMeanError();
meanerror[0][4]=Reco_Onia_CPM0_PU_4->GetMeanError();
meanerror[0][5]=Reco_Onia_CPM0_PU_5->GetMeanError();
meanerror[0][6]=Reco_Onia_CPM0_PU_6->GetMeanError();
meanerror[0][7]=Reco_Onia_CPM0_PU_7->GetMeanError();
meanerror[0][8]=Reco_Onia_CPM0_PU_8->GetMeanError();
meanerror[0][9]=Reco_Onia_CPM0_PU_9->GetMeanError();
meanerror[0][10]=Reco_Onia_CPM0_PU_10->GetMeanError();
meanerror[0][11]=Reco_Onia_CPM0_PU_11->GetMeanError();
meanerror[0][12]=Reco_Onia_CPM0_PU_12->GetMeanError();
meanerror[0][13]=Reco_Onia_CPM0_PU_13->GetMeanError();
meanerror[0][14]=Reco_Onia_CPM0_PU_14->GetMeanError();
meanerror[0][15]=Reco_Onia_CPM0_PU_15->GetMeanError();
meanerror[0][16]=Reco_Onia_CPM0_PU_16->GetMeanError();
meanerror[0][17]=Reco_Onia_CPM0_PU_17->GetMeanError();
meanerror[0][18]=Reco_Onia_CPM0_PU_18->GetMeanError();
meanerror[0][19]=Reco_Onia_CPM0_PU_19->GetMeanError();
meanerror[0][20]=Reco_Onia_CPM0_PU_20->GetMeanError();
meanerror[0][21]=Reco_Onia_CPM0_PU_21->GetMeanError();
meanerror[0][22]=Reco_Onia_CPM0_PU_22->GetMeanError();
meanerror[0][23]=Reco_Onia_CPM0_PU_23->GetMeanError();
meanerror[0][24]=Reco_Onia_CPM0_PU_24->GetMeanError();

meanerror[1][0]=Reco_Onia_CPM1_PU_0->GetMeanError();
meanerror[1][1]=Reco_Onia_CPM1_PU_1->GetMeanError();
meanerror[1][2]=Reco_Onia_CPM1_PU_2->GetMeanError();
meanerror[1][3]=Reco_Onia_CPM1_PU_3->GetMeanError();
meanerror[1][4]=Reco_Onia_CPM1_PU_4->GetMeanError();
meanerror[1][5]=Reco_Onia_CPM1_PU_5->GetMeanError();
meanerror[1][6]=Reco_Onia_CPM1_PU_6->GetMeanError();
meanerror[1][7]=Reco_Onia_CPM1_PU_7->GetMeanError();
meanerror[1][8]=Reco_Onia_CPM1_PU_8->GetMeanError();
meanerror[1][9]=Reco_Onia_CPM1_PU_9->GetMeanError();
meanerror[1][10]=Reco_Onia_CPM1_PU_10->GetMeanError();
meanerror[1][11]=Reco_Onia_CPM1_PU_11->GetMeanError();
meanerror[1][12]=Reco_Onia_CPM1_PU_12->GetMeanError();
meanerror[1][13]=Reco_Onia_CPM1_PU_13->GetMeanError();
meanerror[1][14]=Reco_Onia_CPM1_PU_14->GetMeanError();
meanerror[1][15]=Reco_Onia_CPM1_PU_15->GetMeanError();
meanerror[1][16]=Reco_Onia_CPM1_PU_16->GetMeanError();
meanerror[1][17]=Reco_Onia_CPM1_PU_17->GetMeanError();
meanerror[1][18]=Reco_Onia_CPM1_PU_18->GetMeanError();
meanerror[1][19]=Reco_Onia_CPM1_PU_19->GetMeanError();
meanerror[1][20]=Reco_Onia_CPM1_PU_20->GetMeanError();
meanerror[1][21]=Reco_Onia_CPM1_PU_21->GetMeanError();
meanerror[1][22]=Reco_Onia_CPM1_PU_22->GetMeanError();
meanerror[1][23]=Reco_Onia_CPM1_PU_23->GetMeanError();
meanerror[1][24]=Reco_Onia_CPM1_PU_24->GetMeanError();

meanerror[2][0]=Reco_Onia_CPM2_PU_0->GetMeanError();
meanerror[2][1]=Reco_Onia_CPM2_PU_1->GetMeanError();
meanerror[2][2]=Reco_Onia_CPM2_PU_2->GetMeanError();
meanerror[2][3]=Reco_Onia_CPM2_PU_3->GetMeanError();
meanerror[2][4]=Reco_Onia_CPM2_PU_4->GetMeanError();
meanerror[2][5]=Reco_Onia_CPM2_PU_5->GetMeanError();
meanerror[2][6]=Reco_Onia_CPM2_PU_6->GetMeanError();
meanerror[2][7]=Reco_Onia_CPM2_PU_7->GetMeanError();
meanerror[2][8]=Reco_Onia_CPM2_PU_8->GetMeanError();
meanerror[2][9]=Reco_Onia_CPM2_PU_9->GetMeanError();
meanerror[2][10]=Reco_Onia_CPM2_PU_10->GetMeanError();
meanerror[2][11]=Reco_Onia_CPM2_PU_11->GetMeanError();
meanerror[2][12]=Reco_Onia_CPM2_PU_12->GetMeanError();
meanerror[2][13]=Reco_Onia_CPM2_PU_13->GetMeanError();
meanerror[2][14]=Reco_Onia_CPM2_PU_14->GetMeanError();
meanerror[2][15]=Reco_Onia_CPM2_PU_15->GetMeanError();
meanerror[2][16]=Reco_Onia_CPM2_PU_16->GetMeanError();
meanerror[2][17]=Reco_Onia_CPM2_PU_17->GetMeanError();
meanerror[2][18]=Reco_Onia_CPM2_PU_18->GetMeanError();
meanerror[2][19]=Reco_Onia_CPM2_PU_19->GetMeanError();
meanerror[2][20]=Reco_Onia_CPM2_PU_20->GetMeanError();
meanerror[2][21]=Reco_Onia_CPM2_PU_21->GetMeanError();
meanerror[2][22]=Reco_Onia_CPM2_PU_22->GetMeanError();
meanerror[2][23]=Reco_Onia_CPM2_PU_23->GetMeanError();
meanerror[2][24]=Reco_Onia_CPM2_PU_24->GetMeanError();

meanerror[3][0]=Reco_Onia_CPM3_PU_0->GetMeanError();
meanerror[3][1]=Reco_Onia_CPM3_PU_1->GetMeanError();
meanerror[3][2]=Reco_Onia_CPM3_PU_2->GetMeanError();
meanerror[3][3]=Reco_Onia_CPM3_PU_3->GetMeanError();
meanerror[3][4]=Reco_Onia_CPM3_PU_4->GetMeanError();
meanerror[3][5]=Reco_Onia_CPM3_PU_5->GetMeanError();
meanerror[3][6]=Reco_Onia_CPM3_PU_6->GetMeanError();
meanerror[3][7]=Reco_Onia_CPM3_PU_7->GetMeanError();
meanerror[3][8]=Reco_Onia_CPM3_PU_8->GetMeanError();
meanerror[3][9]=Reco_Onia_CPM3_PU_9->GetMeanError();
meanerror[3][10]=Reco_Onia_CPM3_PU_10->GetMeanError();
meanerror[3][11]=Reco_Onia_CPM3_PU_11->GetMeanError();
meanerror[3][12]=Reco_Onia_CPM3_PU_12->GetMeanError();
meanerror[3][13]=Reco_Onia_CPM3_PU_13->GetMeanError();
meanerror[3][14]=Reco_Onia_CPM3_PU_14->GetMeanError();
meanerror[3][15]=Reco_Onia_CPM3_PU_15->GetMeanError();
meanerror[3][16]=Reco_Onia_CPM3_PU_16->GetMeanError();
meanerror[3][17]=Reco_Onia_CPM3_PU_17->GetMeanError();
meanerror[3][18]=Reco_Onia_CPM3_PU_18->GetMeanError();
meanerror[3][19]=Reco_Onia_CPM3_PU_19->GetMeanError();
meanerror[3][20]=Reco_Onia_CPM3_PU_20->GetMeanError();
meanerror[3][21]=Reco_Onia_CPM3_PU_21->GetMeanError();
meanerror[3][22]=Reco_Onia_CPM3_PU_22->GetMeanError();
meanerror[3][23]=Reco_Onia_CPM3_PU_23->GetMeanError();
meanerror[3][24]=Reco_Onia_CPM3_PU_24->GetMeanError();

meanerror[4][0]=Reco_Onia_CPM4_PU_0->GetMeanError();
meanerror[4][1]=Reco_Onia_CPM4_PU_1->GetMeanError();
meanerror[4][2]=Reco_Onia_CPM4_PU_2->GetMeanError();
meanerror[4][3]=Reco_Onia_CPM4_PU_3->GetMeanError();
meanerror[4][4]=Reco_Onia_CPM4_PU_4->GetMeanError();
meanerror[4][5]=Reco_Onia_CPM4_PU_5->GetMeanError();
meanerror[4][6]=Reco_Onia_CPM4_PU_6->GetMeanError();
meanerror[4][7]=Reco_Onia_CPM4_PU_7->GetMeanError();
meanerror[4][8]=Reco_Onia_CPM4_PU_8->GetMeanError();
meanerror[4][9]=Reco_Onia_CPM4_PU_9->GetMeanError();
meanerror[4][10]=Reco_Onia_CPM4_PU_10->GetMeanError();
meanerror[4][11]=Reco_Onia_CPM4_PU_11->GetMeanError();
meanerror[4][12]=Reco_Onia_CPM4_PU_12->GetMeanError();
meanerror[4][13]=Reco_Onia_CPM4_PU_13->GetMeanError();
meanerror[4][14]=Reco_Onia_CPM4_PU_14->GetMeanError();
meanerror[4][15]=Reco_Onia_CPM4_PU_15->GetMeanError();
meanerror[4][16]=Reco_Onia_CPM4_PU_16->GetMeanError();
meanerror[4][17]=Reco_Onia_CPM4_PU_17->GetMeanError();
meanerror[4][18]=Reco_Onia_CPM4_PU_18->GetMeanError();
meanerror[4][19]=Reco_Onia_CPM4_PU_19->GetMeanError();
meanerror[4][20]=Reco_Onia_CPM4_PU_20->GetMeanError();
meanerror[4][21]=Reco_Onia_CPM4_PU_21->GetMeanError();
meanerror[4][22]=Reco_Onia_CPM4_PU_22->GetMeanError();
meanerror[4][23]=Reco_Onia_CPM4_PU_23->GetMeanError();
meanerror[4][24]=Reco_Onia_CPM4_PU_24->GetMeanError();

//setting up x-axis for TGraphs. x = 0 means 1 primary vertex and 0 pile up
Double_t PUcount[25];
for(int x = 0; x < 25; x++)
{
PUcount[x]=x;
}



//Variables to hold mean and error for the TGraphs
Double_t meanforTGraph[25];
Double_t meanerrorforTGraph[25];

//////////////////////////////////////////////////
//Nch bin 1, <Nch> vs PU, this is repeated once
//for each of the 5 Nch bins
//////////////////////////////////////////////////
  for(int iPU = 0; iPU < 25; iPU++) {
    //changing from a 2D array to 1D in order to make a TGraph
    meanforTGraph[iPU]=mean[0][iPU];
    meanerrorforTGraph[iPU]=meanerror[0][iPU];
  }

  //Create new canvas whenever making a new plot
  TCanvas *c1 = new TCanvas("<Nch> vs PU","<Nch> vs PU",600,400);
  //here's the tgraph based on the values established above
  PU1 = new TGraphErrors(25,PUcount,meanforTGraph,0,meanerrorforTGraph);
  //the fit
  TF1 *fit1 = new TF1("fit1","pol1",0,25);
  PU1->SetMarkerColor(1);
  PU1->GetXaxis()->SetLimits(-1,25);
  fit1->SetLineColor(1);
  fit1->SetLineWidth(1);
  PU1->Fit(fit1,"EMF");
  PU1->SetTitle("0 < N_{ch} < 10");
  PU1->SetMarkerStyle(20);
  PU1->GetYaxis()->SetTitle("< N_{ch} >");
  PU1->GetXaxis()->SetTitle("Number of pileup collisions");
  //getting the slope and intercept of the fit and assigning to a variable
  Double_t p01 = PU1->GetFunction("fit1")->GetParameter(0);
  Double_t p11 = PU1->GetFunction("fit1")->GetParameter(1);
  //getting the errors - this are all identical across all Nch bins
  Double_t e01 = PU1->GetFunction("fit1")->GetParError(0);
  Double_t e11 = PU1->GetFunction("fit1")->GetParError(1);
  PU1->Draw("ap");
  c1->SaveAs("MultiplicityBin1.pdf");

//////////////////////////////////////////////////
//Nch bin 2, <Nch> vs PU, this is repeated once
//for each of the 5 Nch bins
//////////////////////////////////////////////////
  for(int iPU = 0; iPU < 25; iPU++) {
    meanforTGraph[iPU]=mean[1][iPU];
    meanerrorforTGraph[iPU]=meanerror[1][iPU];
  }
  
  TCanvas *c1 = new TCanvas("<Nch> vs PU","<Nch> vs PU",600,400);
  PU2 = new TGraphErrors(25,PUcount,meanforTGraph,0,meanerrorforTGraph);
  TF1 *fit2 = new TF1("fit2","pol1",0,25);
  PU2->SetMarkerColor(2);
  PU2->GetXaxis()->SetLimits(-1,25);
  fit2->SetLineColor(2);
  fit2->SetLineWidth(1);
  PU2->Fit(fit2,"EMF");
  PU2->SetTitle("10 < N_{ch} < 20");
  PU2->SetMarkerStyle(20);
  PU2->GetYaxis()->SetTitle("<N_{ch}>");
  PU2->GetXaxis()->SetTitle("Number of pileup collisions");
  Double_t p02 = PU2->GetFunction("fit2")->GetParameter(0);
  Double_t p12 = PU2->GetFunction("fit2")->GetParameter(1);
  Double_t e02 = PU2->GetFunction("fit2")->GetParError(0);
  Double_t e12 = PU2->GetFunction("fit2")->GetParError(1);
  PU2->Draw("ap");
  c1->SaveAs("MultiplicityBin2.pdf");
  
//////////////////////////////////////////////////
//Nch bin 3, <Nch> vs PU, this is repeated once
//for each of the 5 Nch bins
//////////////////////////////////////////////////
  TCanvas *c1 = new TCanvas("<Nch> vs PU","<Nch> vs PU",600,400);
  for(int iPU = 0; iPU < 25; iPU++) {
    meanforTGraph[iPU]=mean[2][iPU];
    meanerrorforTGraph[iPU]=meanerror[2][iPU];
  }
  
  PU3 = new TGraphErrors(25,PUcount,meanforTGraph,0,meanerrorforTGraph);
  TF1 *fit3 = new TF1("fit3","pol1",0,25);
  PU3->SetMarkerColor(3);
  PU3->GetXaxis()->SetLimits(-1,25);
  fit3->SetLineColor(3);
  fit3->SetLineWidth(1);
  PU3->Fit(fit3,"EMF");
  PU3->SetMarkerStyle(20);
  PU3->SetTitle("20 < N_{ch} < 30");
  PU3->GetYaxis()->SetTitle("<N_{ch}>");
  PU3->GetXaxis()->SetTitle("Number of pileup collisions");
  Double_t p03 = PU3->GetFunction("fit3")->GetParameter(0);
  Double_t p13 = PU3->GetFunction("fit3")->GetParameter(1);
  Double_t e03 = PU3->GetFunction("fit3")->GetParError(0);
  Double_t e13 = PU3->GetFunction("fit3")->GetParError(1);
  PU3->Draw("ap");
  c1->SaveAs("MultiplicityBin3.pdf");
  
//////////////////////////////////////////////////
//Nch bin 4, <Nch> vs PU, this is repeated once
//for each of the 5 Nch bins
//////////////////////////////////////////////////
  TCanvas *c1 = new TCanvas("<Nch> vs PU","<Nch> vs PU",600,400);
  
  for(int iPU = 0; iPU < 25; iPU++) {
    meanforTGraph[iPU]=mean[3][iPU];
    meanerrorforTGraph[iPU]=meanerror[3][iPU];
  }
  
  PU4 = new TGraphErrors(25,PUcount,meanforTGraph,0,meanerrorforTGraph);
  TF1 *fit4 = new TF1("fit4","pol1",0,25);
  PU4->SetMarkerColor(4);
  PU4->GetXaxis()->SetLimits(-1,25);
  fit4->SetLineColor(4);
  fit4->SetLineWidth(1);
  PU4->Fit(fit4,"EMF");
  PU4->SetTitle("30 < N_{ch} < 40");
  PU4->SetMarkerStyle(20);
  PU4->GetYaxis()->SetTitle("<N_{ch}>");
  PU4->GetXaxis()->SetTitle("Number of pileup collisions");
  Double_t p04 = PU4->GetFunction("fit4")->GetParameter(0);
  Double_t p14 = PU4->GetFunction("fit4")->GetParameter(1);
  Double_t e04 = PU4->GetFunction("fit4")->GetParError(0);
  Double_t e14 = PU4->GetFunction("fit4")->GetParError(1);
  PU4->Draw("ap");
  c1->SaveAs("MultiplicityBin4.pdf");
  
//////////////////////////////////////////////////
//Nch bin 5, <Nch> vs PU, this is repeated once
//for each of the 5 Nch bins
//////////////////////////////////////////////////
  TCanvas *c1 = new TCanvas("<Nch> vs PU","<Nch> vs PU",600,400);
  
  for(int iPU = 0; iPU < 25; iPU++) {
    meanforTGraph[iPU]=mean[4][iPU];
    meanerrorforTGraph[iPU]=meanerror[4][iPU];
  }
  
  PU5 = new TGraphErrors(25,PUcount,meanforTGraph,0,meanerrorforTGraph);
  TF1 *fit5 = new TF1("fit5","pol1",0,25);
  PU5->SetMarkerColor(6);
  PU5->GetXaxis()->SetLimits(-1,25);
  fit5->SetLineColor(6);
  fit5->SetLineWidth(1);
  PU5->Fit(fit5,"EMF");
  PU5->SetMarkerStyle(20);
  PU5->SetTitle("40 < N_{ch} < 60");
  PU5->GetYaxis()->SetTitle("<N_{ch}>");
  PU5->GetXaxis()->SetTitle("Number of pileup collisions");

  Double_t p05 = PU5->GetFunction("fit5")->GetParameter(0);
  Double_t p15 = PU5->GetFunction("fit5")->GetParameter(1);
  Double_t e05 = PU5->GetFunction("fit5")->GetParError(0);
  Double_t e15 = PU5->GetFunction("fit5")->GetParError(1);
  PU5->Draw("ap");
  c1->SaveAs("MultiplicityBin5.pdf");
//////////////////////////////////////////////////
//End plotting of <Nch> vs PU 
//////////////////////////////////////////////////

//assigns the intercept value and error to an array to be used for 
//Nch_NoPU/Nch_IntegratedPU ratio plot
Double_t puarray[5]; 
Double_t puarrayerror[5]; 
puarray[0] = p01;
puarray[1] = p02;
puarray[2] = p03;
puarray[3] = p04;
puarray[4] = p05;
puarrayerror[0] = e01;
puarrayerror[1] = e02;
puarrayerror[2] = e03;
puarrayerror[3] = e04;
puarrayerror[4] = e05;

//assigns the Nch_IntegratedPU mean and error for the 
// Nch_NoPU/Nch_IntegratedPU ratio plot
Double_t NchAvgIntPriVtx[5];
Double_t NchAvgIntPriVtxError[5];
NchAvgIntPriVtx[0] = binnedNch_0->GetMean();
NchAvgIntPriVtxError[0] = binnedNch_0->GetMeanError();
NchAvgIntPriVtx[1] = binnedNch_1->GetMean();
NchAvgIntPriVtxError[1] = binnedNch_1->GetMeanError(); 
NchAvgIntPriVtx[2] = binnedNch_2->GetMean();
NchAvgIntPriVtxError[2] = binnedNch_2->GetMeanError();
NchAvgIntPriVtx[3] = binnedNch_3->GetMean();
NchAvgIntPriVtxError[3] = binnedNch_3->GetMeanError();
NchAvgIntPriVtx[4] = binnedNch_4->GetMean();
NchAvgIntPriVtxError[4] = binnedNch_4->GetMeanError();  

/*
cout<<"error is "<<NchAvgIntPriVtxError[0]<<endl;
cout<<"error is "<<NchAvgIntPriVtxError[1]<<endl;
cout<<"error is "<<NchAvgIntPriVtxError[2]<<endl;
cout<<"error is "<<NchAvgIntPriVtxError[3]<<endl;
cout<<"error is "<<NchAvgIntPriVtxError[4]<<endl;
*/

//set x points for ratio plot: 1 = Nch bin 1, 2 = bin 2, etc.
Double_t xpoints[5];
for(int x = 0; x < 5; x++) {
xpoints[x]=x+1;
}

//calculate ratio and standard error of mean for each Nch bin
Double_t ratio[5];
Double_t ratioerror[5];
for(int iCPM = 0; iCPM < 5; iCPM++) 
{
//ratio is straight forward division
ratio[iCPM]=puarray[iCPM]/NchAvgIntPriVtx[iCPM];

//standard error of mean calculated:
Double_t stdev = pow(NchAvgIntPriVtxError[iCPM]/NchAvgIntPriVtx[iCPM],2) + pow(puarrayerror[iCPM]/puarray[iCPM],2);
ratioerror[iCPM]= ratio[iCPM]*sqrt( stdev  );
//cout<<"ratio is "<<ratio[iCPM]<<" and error is "<<ratioerror[iCPM]<<endl;
}  
 
 TCanvas *c1 = new TCanvas("<Nch> vs PU","<Nch> vs PU",600,400);
 theratios = new TGraphErrors(5,xpoints,ratio,0,ratioerror);
 theratios->SetMarkerStyle(20);
 theratios->GetXaxis()->SetTitle("Nch Bin");
 theratios->SetTitle("Nch_NoPU over Nch_Integrated Ratio");
 theratios->Draw("ap"); 
 c1->SaveAs("ratios.pdf");
 
//drawing the <Nch> vs PU TGraphs on one canvas 
TCanvas *c1 = new TCanvas("<Nch> vs PU","<Nch> vs PU",400,400);
PU1->GetYaxis()->SetRangeUser(0, 60);
PU1->SetTitle("");
PU1->GetXaxis()->SetLimits(-1,25);
PU1->SetMarkerSize(0.5);
PU2->SetMarkerSize(0.5);
PU3->SetMarkerSize(0.5);
PU4->SetMarkerSize(0.5);
PU5->SetMarkerSize(0.5);
PU1->Draw("ap");
PU2->Draw("p");
PU3->Draw("p");
PU4->Draw("p");
PU5->Draw("p");
//leg = new TLegend(0.775,0.7,0.9,0.9);
//leg->SetFillColor(0);
//leg->AddEntry(PU1,"Nch bin 1","p");
//leg->AddEntry(PU2,"Nch bin 2","p");
//leg->AddEntry(PU3,"Nch bin 3","p");
//leg->AddEntry(PU4,"Nch bin 4","p");
//leg->AddEntry(PU5,"Nch bin 5","p");
//leg->Draw();
c1->SaveAs("AverageNch_vs_PU.pdf");

//drawing the <Nch> vs PU TGraphs on one canvas, this time in log y
TCanvas *c1 = new TCanvas("<Nch> vs PU","<Nch> vs PU",400,400);
c1->SetLogy();
PU1->SetMinimum(1);
PU1->SetMaximum(100);
PU1->GetXaxis()->SetLimits(-1,25);
PU1->Draw("ap");
PU2->Draw("p");
PU3->Draw("p");
PU4->Draw("p");
PU5->Draw("p");
leg = new TLegend(0.775,0.1,0.9,0.35);
leg->SetFillColor(0);
leg->AddEntry(PU1,"Nch bin 1","p");
leg->AddEntry(PU2,"Nch bin 2","p");
leg->AddEntry(PU3,"Nch bin 3","p");
leg->AddEntry(PU4,"Nch bin 4","p");
leg->AddEntry(PU5,"Nch bin 5","p");
leg->Draw();
c1->SaveAs("log_overall.pdf");


//one final plot: <Nch> - Nch_NoPU vs Nch bin
TCanvas *c1 = new TCanvas("<Nch> - Nch_NoPU","<Nch> - Nch_NoPU",600,400);
//set up the arrays to be filled
double avg_min_0PU[5];
double avg_min_0PUerror[5];
for(int x = 0; x < 5; x++){
//simple subtraction of <Nch> - Nch_NoPU
avg_min_0PU[x] = NchAvgIntPriVtx[x]-puarray[x];
//calculation of error
avg_min_0PUerror[x] = sqrt(pow(puarrayerror[x],2) + pow(NchAvgIntPriVtxError[x],2));
}
gravg_min_0PU = new TGraphErrors(5,xpoints, avg_min_0PU,0,avg_min_0PUerror);
gravg_min_0PU->SetMarkerStyle(20);
gravg_min_0PU->GetYaxis()->SetTitle("<Nch> - Nch_NoPU");
gravg_min_0PU->GetXaxis()->SetTitle("Nch bin");
gravg_min_0PU->SetTitle("");
gravg_min_0PU->Draw("ap");
c1->SaveAs("avg_min_0PU.pdf");

/*
for(int x = 0; x < 5; x++){
cout<<"nPriVtx  <Nch>   Error"<<endl;
for(int y = 0; y < 25; y++){
cout<<y+1<<" "<<mean[x][y]<<" "<<meanerror[x][y]<<endl;
}
}
  */
  
//print out info for latex:
// bin, Nch_IntegratedPU, Nch_NoPU, Slope with error, Intercept with error

cout<<"$N_{ch}$ Bin & $N_{ch}$ Integrated & $N_{ch}$ Zero PU & $N_{ch}$ Integrated/$N_{ch}$ Integrated \\\\ \\hline"<<endl;
cout<<"  0--10 & "<<NchAvgIntPriVtx[0]<<"\\+-"<<NchAvgIntPriVtxError[0]<<" & "<<p01<<"\\+-"<<e01<<" & "<<ratio[0]<<"\\+-"<<ratioerror[0]<<" & "<<" \\hline"<<endl;
cout<<" 10--20 & "<<NchAvgIntPriVtx[1]<<"\\+-"<<NchAvgIntPriVtxError[1]<<" & "<<p02<<"\\+-"<<e02<<" & "<<ratio[1]<<"\\+-"<<ratioerror[1]<<" & "<<" \\hline"<<endl;
cout<<" 20--30 & "<<NchAvgIntPriVtx[2]<<"\\+-"<<NchAvgIntPriVtxError[2]<<" & "<<p03<<"\\+-"<<e03<<" & "<<ratio[2]<<"\\+-"<<ratioerror[2]<<" & "<<" \\hline"<<endl;
cout<<" 30--40 & "<<NchAvgIntPriVtx[3]<<"\\+-"<<NchAvgIntPriVtxError[3]<<" & "<<p04<<"\\+-"<<e04<<" & "<<ratio[3]<<"\\+-"<<ratioerror[3]<<" & "<<" \\hline"<<endl;
cout<<" 40--60 & "<<NchAvgIntPriVtx[4]<<"\\+-"<<NchAvgIntPriVtxError[4]<<" & "<<p05<<"\\+-"<<e05<<" & "<<ratio[4]<<"\\+-"<<ratioerror[4]<<" & "<<" \\hline"<<endl;
  }
