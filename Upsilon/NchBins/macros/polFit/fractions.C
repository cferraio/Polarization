//this file is the output of polData.C -> same exact code used for the analysis, 
//just with added functionality to plot Nch distros in nPriVtx bins

{TFile f("../DataFiles/SetOfCuts11_countTksOfPV/tmpFiles/selEvents_data_Ups.root");



Double_t XSecIntegral[5][25];
Double_t XSecIntegralError[5][25];
Double_t XSecFraction0[25];
Double_t XSecFraction1[25];
Double_t XSecFraction2[25];
Double_t XSecFraction3[25];
Double_t XSecFraction4[25];
Double_t XSecFractionError0[25];
Double_t XSecFractionError1[25];
Double_t XSecFractionError2[25];
Double_t XSecFractionError3[25];
Double_t XSecFractionError4[25];


XSecIntegral[0][0]=Reco_Onia_CPM0_PU_0->Integral();
XSecIntegral[0][1]=Reco_Onia_CPM0_PU_1->Integral();
XSecIntegral[0][2]=Reco_Onia_CPM0_PU_2->Integral();
XSecIntegral[0][3]=Reco_Onia_CPM0_PU_3->Integral();
XSecIntegral[0][4]=Reco_Onia_CPM0_PU_4->Integral();
XSecIntegral[0][5]=Reco_Onia_CPM0_PU_5->Integral();
XSecIntegral[0][6]=Reco_Onia_CPM0_PU_6->Integral();
XSecIntegral[0][7]=Reco_Onia_CPM0_PU_7->Integral();
XSecIntegral[0][8]=Reco_Onia_CPM0_PU_8->Integral();
XSecIntegral[0][9]=Reco_Onia_CPM0_PU_9->Integral();
XSecIntegral[0][10]=Reco_Onia_CPM0_PU_10->Integral();
XSecIntegral[0][11]=Reco_Onia_CPM0_PU_11->Integral();
XSecIntegral[0][12]=Reco_Onia_CPM0_PU_12->Integral();
XSecIntegral[0][13]=Reco_Onia_CPM0_PU_13->Integral();
XSecIntegral[0][14]=Reco_Onia_CPM0_PU_14->Integral();
XSecIntegral[0][15]=Reco_Onia_CPM0_PU_15->Integral();
XSecIntegral[0][16]=Reco_Onia_CPM0_PU_16->Integral();
XSecIntegral[0][17]=Reco_Onia_CPM0_PU_17->Integral();
XSecIntegral[0][18]=Reco_Onia_CPM0_PU_18->Integral();
XSecIntegral[0][19]=Reco_Onia_CPM0_PU_19->Integral();
XSecIntegral[0][20]=Reco_Onia_CPM0_PU_20->Integral();
XSecIntegral[0][21]=Reco_Onia_CPM0_PU_21->Integral();
XSecIntegral[0][22]=Reco_Onia_CPM0_PU_22->Integral();
XSecIntegral[0][23]=Reco_Onia_CPM0_PU_23->Integral();
XSecIntegral[0][24]=Reco_Onia_CPM0_PU_24->Integral();

XSecIntegral[1][0]=Reco_Onia_CPM1_PU_0->Integral();
XSecIntegral[1][1]=Reco_Onia_CPM1_PU_1->Integral();
XSecIntegral[1][2]=Reco_Onia_CPM1_PU_2->Integral();
XSecIntegral[1][3]=Reco_Onia_CPM1_PU_3->Integral();
XSecIntegral[1][4]=Reco_Onia_CPM1_PU_4->Integral();
XSecIntegral[1][5]=Reco_Onia_CPM1_PU_5->Integral();
XSecIntegral[1][6]=Reco_Onia_CPM1_PU_6->Integral();
XSecIntegral[1][7]=Reco_Onia_CPM1_PU_7->Integral();
XSecIntegral[1][8]=Reco_Onia_CPM1_PU_8->Integral();
XSecIntegral[1][9]=Reco_Onia_CPM1_PU_9->Integral();
XSecIntegral[1][10]=Reco_Onia_CPM1_PU_10->Integral();
XSecIntegral[1][11]=Reco_Onia_CPM1_PU_11->Integral();
XSecIntegral[1][12]=Reco_Onia_CPM1_PU_12->Integral();
XSecIntegral[1][13]=Reco_Onia_CPM1_PU_13->Integral();
XSecIntegral[1][14]=Reco_Onia_CPM1_PU_14->Integral();
XSecIntegral[1][15]=Reco_Onia_CPM1_PU_15->Integral();
XSecIntegral[1][16]=Reco_Onia_CPM1_PU_16->Integral();
XSecIntegral[1][17]=Reco_Onia_CPM1_PU_17->Integral();
XSecIntegral[1][18]=Reco_Onia_CPM1_PU_18->Integral();
XSecIntegral[1][19]=Reco_Onia_CPM1_PU_19->Integral();
XSecIntegral[1][20]=Reco_Onia_CPM1_PU_20->Integral();
XSecIntegral[1][21]=Reco_Onia_CPM1_PU_21->Integral();
XSecIntegral[1][22]=Reco_Onia_CPM1_PU_22->Integral();
XSecIntegral[1][23]=Reco_Onia_CPM1_PU_23->Integral();
XSecIntegral[1][24]=Reco_Onia_CPM1_PU_24->Integral();

XSecIntegral[2][0]=Reco_Onia_CPM2_PU_0->Integral();
XSecIntegral[2][1]=Reco_Onia_CPM2_PU_1->Integral();
XSecIntegral[2][2]=Reco_Onia_CPM2_PU_2->Integral();
XSecIntegral[2][3]=Reco_Onia_CPM2_PU_3->Integral();
XSecIntegral[2][4]=Reco_Onia_CPM2_PU_4->Integral();
XSecIntegral[2][5]=Reco_Onia_CPM2_PU_5->Integral();
XSecIntegral[2][6]=Reco_Onia_CPM2_PU_6->Integral();
XSecIntegral[2][7]=Reco_Onia_CPM2_PU_7->Integral();
XSecIntegral[2][8]=Reco_Onia_CPM2_PU_8->Integral();
XSecIntegral[2][9]=Reco_Onia_CPM2_PU_9->Integral();
XSecIntegral[2][10]=Reco_Onia_CPM2_PU_10->Integral();
XSecIntegral[2][11]=Reco_Onia_CPM2_PU_11->Integral();
XSecIntegral[2][12]=Reco_Onia_CPM2_PU_12->Integral();
XSecIntegral[2][13]=Reco_Onia_CPM2_PU_13->Integral();
XSecIntegral[2][14]=Reco_Onia_CPM2_PU_14->Integral();
XSecIntegral[2][15]=Reco_Onia_CPM2_PU_15->Integral();
XSecIntegral[2][16]=Reco_Onia_CPM2_PU_16->Integral();
XSecIntegral[2][17]=Reco_Onia_CPM2_PU_17->Integral();
XSecIntegral[2][18]=Reco_Onia_CPM2_PU_18->Integral();
XSecIntegral[2][19]=Reco_Onia_CPM2_PU_19->Integral();
XSecIntegral[2][20]=Reco_Onia_CPM2_PU_20->Integral();
XSecIntegral[2][21]=Reco_Onia_CPM2_PU_21->Integral();
XSecIntegral[2][22]=Reco_Onia_CPM2_PU_22->Integral();
XSecIntegral[2][23]=Reco_Onia_CPM2_PU_23->Integral();
XSecIntegral[2][24]=Reco_Onia_CPM2_PU_24->Integral();

XSecIntegral[3][0]=Reco_Onia_CPM3_PU_0->Integral();
XSecIntegral[3][1]=Reco_Onia_CPM3_PU_1->Integral();
XSecIntegral[3][2]=Reco_Onia_CPM3_PU_2->Integral();
XSecIntegral[3][3]=Reco_Onia_CPM3_PU_3->Integral();
XSecIntegral[3][4]=Reco_Onia_CPM3_PU_4->Integral();
XSecIntegral[3][5]=Reco_Onia_CPM3_PU_5->Integral();
XSecIntegral[3][6]=Reco_Onia_CPM3_PU_6->Integral();
XSecIntegral[3][7]=Reco_Onia_CPM3_PU_7->Integral();
XSecIntegral[3][8]=Reco_Onia_CPM3_PU_8->Integral();
XSecIntegral[3][9]=Reco_Onia_CPM3_PU_9->Integral();
XSecIntegral[3][10]=Reco_Onia_CPM3_PU_10->Integral();
XSecIntegral[3][11]=Reco_Onia_CPM3_PU_11->Integral();
XSecIntegral[3][12]=Reco_Onia_CPM3_PU_12->Integral();
XSecIntegral[3][13]=Reco_Onia_CPM3_PU_13->Integral();
XSecIntegral[3][14]=Reco_Onia_CPM3_PU_14->Integral();
XSecIntegral[3][15]=Reco_Onia_CPM3_PU_15->Integral();
XSecIntegral[3][16]=Reco_Onia_CPM3_PU_16->Integral();
XSecIntegral[3][17]=Reco_Onia_CPM3_PU_17->Integral();
XSecIntegral[3][18]=Reco_Onia_CPM3_PU_18->Integral();
XSecIntegral[3][19]=Reco_Onia_CPM3_PU_19->Integral();
XSecIntegral[3][20]=Reco_Onia_CPM3_PU_20->Integral();
XSecIntegral[3][21]=Reco_Onia_CPM3_PU_21->Integral();
XSecIntegral[3][22]=Reco_Onia_CPM3_PU_22->Integral();
XSecIntegral[3][23]=Reco_Onia_CPM3_PU_23->Integral();
XSecIntegral[3][24]=Reco_Onia_CPM3_PU_24->Integral();

XSecIntegral[4][0]=Reco_Onia_CPM4_PU_0->Integral();
XSecIntegral[4][1]=Reco_Onia_CPM4_PU_1->Integral();
XSecIntegral[4][2]=Reco_Onia_CPM4_PU_2->Integral();
XSecIntegral[4][3]=Reco_Onia_CPM4_PU_3->Integral();
XSecIntegral[4][4]=Reco_Onia_CPM4_PU_4->Integral();
XSecIntegral[4][5]=Reco_Onia_CPM4_PU_5->Integral();
XSecIntegral[4][6]=Reco_Onia_CPM4_PU_6->Integral();
XSecIntegral[4][7]=Reco_Onia_CPM4_PU_7->Integral();
XSecIntegral[4][8]=Reco_Onia_CPM4_PU_8->Integral();
XSecIntegral[4][9]=Reco_Onia_CPM4_PU_9->Integral();
XSecIntegral[4][10]=Reco_Onia_CPM4_PU_10->Integral();
XSecIntegral[4][11]=Reco_Onia_CPM4_PU_11->Integral();
XSecIntegral[4][12]=Reco_Onia_CPM4_PU_12->Integral();
XSecIntegral[4][13]=Reco_Onia_CPM4_PU_13->Integral();
XSecIntegral[4][14]=Reco_Onia_CPM4_PU_14->Integral();
XSecIntegral[4][15]=Reco_Onia_CPM4_PU_15->Integral();
XSecIntegral[4][16]=Reco_Onia_CPM4_PU_16->Integral();
XSecIntegral[4][17]=Reco_Onia_CPM4_PU_17->Integral();
XSecIntegral[4][18]=Reco_Onia_CPM4_PU_18->Integral();
XSecIntegral[4][19]=Reco_Onia_CPM4_PU_19->Integral();
XSecIntegral[4][20]=Reco_Onia_CPM4_PU_20->Integral();
XSecIntegral[4][21]=Reco_Onia_CPM4_PU_21->Integral();
XSecIntegral[4][22]=Reco_Onia_CPM4_PU_22->Integral();
XSecIntegral[4][23]=Reco_Onia_CPM4_PU_23->Integral();
XSecIntegral[4][24]=Reco_Onia_CPM4_PU_24->Integral();



Reco_Onia_CPM0_PU_0->IntegralAndError(0,-1,XSecIntegralError[0][0]);
Reco_Onia_CPM0_PU_1->IntegralAndError(0,-1,XSecIntegralError[0][1]);
Reco_Onia_CPM0_PU_2->IntegralAndError(0,-1,XSecIntegralError[0][2]);
Reco_Onia_CPM0_PU_3->IntegralAndError(0,-1,XSecIntegralError[0][3]);
Reco_Onia_CPM0_PU_4->IntegralAndError(0,-1,XSecIntegralError[0][4]);
Reco_Onia_CPM0_PU_5->IntegralAndError(0,-1,XSecIntegralError[0][5]);
Reco_Onia_CPM0_PU_6->IntegralAndError(0,-1,XSecIntegralError[0][6]);
Reco_Onia_CPM0_PU_7->IntegralAndError(0,-1,XSecIntegralError[0][7]);
Reco_Onia_CPM0_PU_8->IntegralAndError(0,-1,XSecIntegralError[0][8]);
Reco_Onia_CPM0_PU_9->IntegralAndError(0,-1,XSecIntegralError[0][9]);
Reco_Onia_CPM0_PU_10->IntegralAndError(0,-1,XSecIntegralError[0][10]);
Reco_Onia_CPM0_PU_11->IntegralAndError(0,-1,XSecIntegralError[0][11]);
Reco_Onia_CPM0_PU_12->IntegralAndError(0,-1,XSecIntegralError[0][12]);
Reco_Onia_CPM0_PU_13->IntegralAndError(0,-1,XSecIntegralError[0][13]);
Reco_Onia_CPM0_PU_14->IntegralAndError(0,-1,XSecIntegralError[0][14]);
Reco_Onia_CPM0_PU_15->IntegralAndError(0,-1,XSecIntegralError[0][15]);
Reco_Onia_CPM0_PU_16->IntegralAndError(0,-1,XSecIntegralError[0][16]);
Reco_Onia_CPM0_PU_17->IntegralAndError(0,-1,XSecIntegralError[0][17]);
Reco_Onia_CPM0_PU_18->IntegralAndError(0,-1,XSecIntegralError[0][18]);
Reco_Onia_CPM0_PU_19->IntegralAndError(0,-1,XSecIntegralError[0][19]);
Reco_Onia_CPM0_PU_20->IntegralAndError(0,-1,XSecIntegralError[0][20]);
Reco_Onia_CPM0_PU_21->IntegralAndError(0,-1,XSecIntegralError[0][21]);
Reco_Onia_CPM0_PU_22->IntegralAndError(0,-1,XSecIntegralError[0][22]);
Reco_Onia_CPM0_PU_23->IntegralAndError(0,-1,XSecIntegralError[0][23]);
Reco_Onia_CPM0_PU_24->IntegralAndError(0,-1,XSecIntegralError[0][24]);

Reco_Onia_CPM1_PU_0->IntegralAndError(0,-1,XSecIntegralError[1][0]);
Reco_Onia_CPM1_PU_1->IntegralAndError(0,-1,XSecIntegralError[1][1]);
Reco_Onia_CPM1_PU_2->IntegralAndError(0,-1,XSecIntegralError[1][2]);
Reco_Onia_CPM1_PU_3->IntegralAndError(0,-1,XSecIntegralError[1][3]);
Reco_Onia_CPM1_PU_4->IntegralAndError(0,-1,XSecIntegralError[1][4]);
Reco_Onia_CPM1_PU_5->IntegralAndError(0,-1,XSecIntegralError[1][5]);
Reco_Onia_CPM1_PU_6->IntegralAndError(0,-1,XSecIntegralError[1][6]);
Reco_Onia_CPM1_PU_7->IntegralAndError(0,-1,XSecIntegralError[1][7]);
Reco_Onia_CPM1_PU_8->IntegralAndError(0,-1,XSecIntegralError[1][8]);
Reco_Onia_CPM1_PU_9->IntegralAndError(0,-1,XSecIntegralError[1][9]);
Reco_Onia_CPM1_PU_10->IntegralAndError(0,-1,XSecIntegralError[1][10]);
Reco_Onia_CPM1_PU_11->IntegralAndError(0,-1,XSecIntegralError[1][11]);
Reco_Onia_CPM1_PU_12->IntegralAndError(0,-1,XSecIntegralError[1][12]);
Reco_Onia_CPM1_PU_13->IntegralAndError(0,-1,XSecIntegralError[1][13]);
Reco_Onia_CPM1_PU_14->IntegralAndError(0,-1,XSecIntegralError[1][14]);
Reco_Onia_CPM1_PU_15->IntegralAndError(0,-1,XSecIntegralError[1][15]);
Reco_Onia_CPM1_PU_16->IntegralAndError(0,-1,XSecIntegralError[1][16]);
Reco_Onia_CPM1_PU_17->IntegralAndError(0,-1,XSecIntegralError[1][17]);
Reco_Onia_CPM1_PU_18->IntegralAndError(0,-1,XSecIntegralError[1][18]);
Reco_Onia_CPM1_PU_19->IntegralAndError(0,-1,XSecIntegralError[1][19]);
Reco_Onia_CPM1_PU_20->IntegralAndError(0,-1,XSecIntegralError[1][20]);
Reco_Onia_CPM1_PU_21->IntegralAndError(0,-1,XSecIntegralError[1][21]);
Reco_Onia_CPM1_PU_22->IntegralAndError(0,-1,XSecIntegralError[1][22]);
Reco_Onia_CPM1_PU_23->IntegralAndError(0,-1,XSecIntegralError[1][23]);
Reco_Onia_CPM1_PU_24->IntegralAndError(0,-1,XSecIntegralError[1][24]);

Reco_Onia_CPM2_PU_0->IntegralAndError(0,-1,XSecIntegralError[2][0]);
Reco_Onia_CPM2_PU_1->IntegralAndError(0,-1,XSecIntegralError[2][1]);
Reco_Onia_CPM2_PU_2->IntegralAndError(0,-1,XSecIntegralError[2][2]);
Reco_Onia_CPM2_PU_3->IntegralAndError(0,-1,XSecIntegralError[2][3]);
Reco_Onia_CPM2_PU_4->IntegralAndError(0,-1,XSecIntegralError[2][4]);
Reco_Onia_CPM2_PU_5->IntegralAndError(0,-1,XSecIntegralError[2][5]);
Reco_Onia_CPM2_PU_6->IntegralAndError(0,-1,XSecIntegralError[2][6]);
Reco_Onia_CPM2_PU_7->IntegralAndError(0,-1,XSecIntegralError[2][7]);
Reco_Onia_CPM2_PU_8->IntegralAndError(0,-1,XSecIntegralError[2][8]);
Reco_Onia_CPM2_PU_9->IntegralAndError(0,-1,XSecIntegralError[2][9]);
Reco_Onia_CPM2_PU_10->IntegralAndError(0,-1,XSecIntegralError[2][10]);
Reco_Onia_CPM2_PU_11->IntegralAndError(0,-1,XSecIntegralError[2][11]);
Reco_Onia_CPM2_PU_12->IntegralAndError(0,-1,XSecIntegralError[2][12]);
Reco_Onia_CPM2_PU_13->IntegralAndError(0,-1,XSecIntegralError[2][13]);
Reco_Onia_CPM2_PU_14->IntegralAndError(0,-1,XSecIntegralError[2][14]);
Reco_Onia_CPM2_PU_15->IntegralAndError(0,-1,XSecIntegralError[2][15]);
Reco_Onia_CPM2_PU_16->IntegralAndError(0,-1,XSecIntegralError[2][16]);
Reco_Onia_CPM2_PU_17->IntegralAndError(0,-1,XSecIntegralError[2][17]);
Reco_Onia_CPM2_PU_18->IntegralAndError(0,-1,XSecIntegralError[2][18]);
Reco_Onia_CPM2_PU_19->IntegralAndError(0,-1,XSecIntegralError[2][19]);
Reco_Onia_CPM2_PU_20->IntegralAndError(0,-1,XSecIntegralError[2][20]);
Reco_Onia_CPM2_PU_21->IntegralAndError(0,-1,XSecIntegralError[2][21]);
Reco_Onia_CPM2_PU_22->IntegralAndError(0,-1,XSecIntegralError[2][22]);
Reco_Onia_CPM2_PU_23->IntegralAndError(0,-1,XSecIntegralError[2][23]);
Reco_Onia_CPM2_PU_24->IntegralAndError(0,-1,XSecIntegralError[2][24]);

Reco_Onia_CPM3_PU_0->IntegralAndError(0,-1,XSecIntegralError[3][0]);
Reco_Onia_CPM3_PU_1->IntegralAndError(0,-1,XSecIntegralError[3][1]);
Reco_Onia_CPM3_PU_2->IntegralAndError(0,-1,XSecIntegralError[3][2]);
Reco_Onia_CPM3_PU_3->IntegralAndError(0,-1,XSecIntegralError[3][3]);
Reco_Onia_CPM3_PU_4->IntegralAndError(0,-1,XSecIntegralError[3][4]);
Reco_Onia_CPM3_PU_5->IntegralAndError(0,-1,XSecIntegralError[3][5]);
Reco_Onia_CPM3_PU_6->IntegralAndError(0,-1,XSecIntegralError[3][6]);
Reco_Onia_CPM3_PU_7->IntegralAndError(0,-1,XSecIntegralError[3][7]);
Reco_Onia_CPM3_PU_8->IntegralAndError(0,-1,XSecIntegralError[3][8]);
Reco_Onia_CPM3_PU_9->IntegralAndError(0,-1,XSecIntegralError[3][9]);
Reco_Onia_CPM3_PU_10->IntegralAndError(0,-1,XSecIntegralError[3][10]);
Reco_Onia_CPM3_PU_11->IntegralAndError(0,-1,XSecIntegralError[3][11]);
Reco_Onia_CPM3_PU_12->IntegralAndError(0,-1,XSecIntegralError[3][12]);
Reco_Onia_CPM3_PU_13->IntegralAndError(0,-1,XSecIntegralError[3][13]);
Reco_Onia_CPM3_PU_14->IntegralAndError(0,-1,XSecIntegralError[3][14]);
Reco_Onia_CPM3_PU_15->IntegralAndError(0,-1,XSecIntegralError[3][15]);
Reco_Onia_CPM3_PU_16->IntegralAndError(0,-1,XSecIntegralError[3][16]);
Reco_Onia_CPM3_PU_17->IntegralAndError(0,-1,XSecIntegralError[3][17]);
Reco_Onia_CPM3_PU_18->IntegralAndError(0,-1,XSecIntegralError[3][18]);
Reco_Onia_CPM3_PU_19->IntegralAndError(0,-1,XSecIntegralError[3][19]);
Reco_Onia_CPM3_PU_20->IntegralAndError(0,-1,XSecIntegralError[3][20]);
Reco_Onia_CPM3_PU_21->IntegralAndError(0,-1,XSecIntegralError[3][21]);
Reco_Onia_CPM3_PU_22->IntegralAndError(0,-1,XSecIntegralError[3][22]);
Reco_Onia_CPM3_PU_23->IntegralAndError(0,-1,XSecIntegralError[3][23]);
Reco_Onia_CPM3_PU_24->IntegralAndError(0,-1,XSecIntegralError[3][24]);

Reco_Onia_CPM4_PU_0->IntegralAndError(0,-1,XSecIntegralError[4][0]);
Reco_Onia_CPM4_PU_1->IntegralAndError(0,-1,XSecIntegralError[4][1]);
Reco_Onia_CPM4_PU_2->IntegralAndError(0,-1,XSecIntegralError[4][2]);
Reco_Onia_CPM4_PU_3->IntegralAndError(0,-1,XSecIntegralError[4][3]);
Reco_Onia_CPM4_PU_4->IntegralAndError(0,-1,XSecIntegralError[4][4]);
Reco_Onia_CPM4_PU_5->IntegralAndError(0,-1,XSecIntegralError[4][5]);
Reco_Onia_CPM4_PU_6->IntegralAndError(0,-1,XSecIntegralError[4][6]);
Reco_Onia_CPM4_PU_7->IntegralAndError(0,-1,XSecIntegralError[4][7]);
Reco_Onia_CPM4_PU_8->IntegralAndError(0,-1,XSecIntegralError[4][8]);
Reco_Onia_CPM4_PU_9->IntegralAndError(0,-1,XSecIntegralError[4][9]);
Reco_Onia_CPM4_PU_10->IntegralAndError(0,-1,XSecIntegralError[4][10]);
Reco_Onia_CPM4_PU_11->IntegralAndError(0,-1,XSecIntegralError[4][11]);
Reco_Onia_CPM4_PU_12->IntegralAndError(0,-1,XSecIntegralError[4][12]);
Reco_Onia_CPM4_PU_13->IntegralAndError(0,-1,XSecIntegralError[4][13]);
Reco_Onia_CPM4_PU_14->IntegralAndError(0,-1,XSecIntegralError[4][14]);
Reco_Onia_CPM4_PU_15->IntegralAndError(0,-1,XSecIntegralError[4][15]);
Reco_Onia_CPM4_PU_16->IntegralAndError(0,-1,XSecIntegralError[4][16]);
Reco_Onia_CPM4_PU_17->IntegralAndError(0,-1,XSecIntegralError[4][17]);
Reco_Onia_CPM4_PU_18->IntegralAndError(0,-1,XSecIntegralError[4][18]);
Reco_Onia_CPM4_PU_19->IntegralAndError(0,-1,XSecIntegralError[4][19]);
Reco_Onia_CPM4_PU_20->IntegralAndError(0,-1,XSecIntegralError[4][20]);
Reco_Onia_CPM4_PU_21->IntegralAndError(0,-1,XSecIntegralError[4][21]);
Reco_Onia_CPM4_PU_22->IntegralAndError(0,-1,XSecIntegralError[4][22]);
Reco_Onia_CPM4_PU_23->IntegralAndError(0,-1,XSecIntegralError[4][23]);
Reco_Onia_CPM4_PU_24->IntegralAndError(0,-1,XSecIntegralError[4][24]);



Double_t IntegralOverNch[25];
Double_t IntegralError[25];


Double_t ErrorForTGraph0[25];
Double_t ErrorForTGraph1[25];
Double_t ErrorForTGraph2[25];
Double_t ErrorForTGraph3[25];
Double_t ErrorForTGraph4[25];



for(int iPU = 0; iPU < 25; iPU++) {
 IntegralOverNch[iPU] = XSecIntegral[0][iPU]+XSecIntegral[1][iPU]+XSecIntegral[2][iPU]+XSecIntegral[3][iPU]+XSecIntegral[4][iPU];
 IntegralError[iPU] = sqrt(pow(XSecIntegralError[0][iPU],2)+pow(XSecIntegralError[1][iPU],2)+pow(XSecIntegralError[2][iPU],2)+pow(XSecIntegralError[3][iPU],2)+pow(XSecIntegralError[4][iPU],2)); 
 XSecFraction0[iPU] = 100.*XSecIntegral[0][iPU] / IntegralOverNch[iPU];
 XSecFraction1[iPU] = 100.*XSecIntegral[1][iPU] / IntegralOverNch[iPU];
 XSecFraction2[iPU] = 100.*XSecIntegral[2][iPU] / IntegralOverNch[iPU];
 XSecFraction3[iPU] = 100.*XSecIntegral[3][iPU] / IntegralOverNch[iPU];
 XSecFraction4[iPU] = 100.*XSecIntegral[4][iPU] / IntegralOverNch[iPU];
 ErrorForTGraph0[iPU]=XSecFraction0[iPU]*sqrt( pow((XSecIntegralError[0][iPU]/XSecIntegral[0][iPU]),2) + pow( (IntegralError[iPU]/IntegralOverNch[iPU]),2) );
 ErrorForTGraph1[iPU]=XSecFraction1[iPU]*sqrt( pow((XSecIntegralError[1][iPU]/XSecIntegral[0][iPU]),2) + pow( (IntegralError[iPU]/IntegralOverNch[iPU]),2) );
 ErrorForTGraph2[iPU]=XSecFraction2[iPU]*sqrt( pow((XSecIntegralError[2][iPU]/XSecIntegral[0][iPU]),2) + pow( (IntegralError[iPU]/IntegralOverNch[iPU]),2) );
 ErrorForTGraph3[iPU]=XSecFraction3[iPU]*sqrt( pow((XSecIntegralError[3][iPU]/XSecIntegral[0][iPU]),2) + pow( (IntegralError[iPU]/IntegralOverNch[iPU]),2) );
 ErrorForTGraph4[iPU]=XSecFraction4[iPU]*sqrt( pow((XSecIntegralError[4][iPU]/XSecIntegral[0][iPU]),2) + pow( (IntegralError[iPU]/IntegralOverNch[iPU]),2) );
}

//setting up x-axis for TGraphs. x = 0 means 1 primary vertex and 0 pile up
Double_t PUcount[25];
for(int x = 0; x < 25; x++)
{
PUcount[x]=x;
}

 TCanvas *c1 = new TCanvas("Fraction of cross section vs. PU","Fraction of cross section vs. PU",400,400);
 TH1F *hFrame = gPad->DrawFrame(-1, 0., 25, 50.);
 hFrame->SetXTitle("Number of pileup collisions");
 hFrame->SetYTitle("Fraction of cross section (%)");
 hFrame->Draw();

 PU1 = new TGraphErrors(25,PUcount,XSecFraction0,0,ErrorForTGraph0);
 PU2 = new TGraphErrors(25,PUcount,XSecFraction1,0,ErrorForTGraph1);
 PU3 = new TGraphErrors(25,PUcount,XSecFraction2,0,ErrorForTGraph2);
 PU4 = new TGraphErrors(25,PUcount,XSecFraction3,0,ErrorForTGraph3);
 PU5 = new TGraphErrors(25,PUcount,XSecFraction4,0,ErrorForTGraph4);

 PU1->SetMarkerStyle(20);
 PU2->SetMarkerStyle(21);
 PU3->SetMarkerStyle(24);
 PU4->SetMarkerStyle(25);
 PU5->SetMarkerStyle(26);

 PU1->SetMarkerColor(1);
 PU2->SetMarkerColor(2);
 PU3->SetMarkerColor(3);
 PU4->SetMarkerColor(4);
 PU5->SetMarkerColor(6);
 PU1->SetLineColor(1);
 PU2->SetLineColor(2);
 PU3->SetLineColor(3);
 PU4->SetLineColor(4);
 PU5->SetLineColor(6);

leg = new TLegend(0.775,0.7,0.9,0.9);
leg->SetFillColor(0);
leg->AddEntry(PU1,"Nch 0-10","p");
leg->AddEntry(PU2,"Nch 10-20","p");
leg->AddEntry(PU3,"Nch 20-30","p");
leg->AddEntry(PU4,"Nch 30-40","p");
leg->AddEntry(PU5,"Nch 40-60","p");
leg->Draw();

PU1->Draw("p");
PU2->Draw("p");
PU3->Draw("p");
PU4->Draw("p");
PU5->Draw("p");

 c1->SaveAs("CrossSectionFraction_bins.pdf");

}
