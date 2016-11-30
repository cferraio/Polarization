{
TFile f("/data/users/ferraioc/Polarization/Modified/Data/GreatCPMRun2_withsys/TGraphResults_1SUps.root");

double lamtildeCS[2][5]={{-0.163407,-0.0625613,0.0113606,-0.221905,-0.267471},{-0.315823,-0.245374,-0.166722,-0.162765,-0.194977}};
double lamtildeHX[2][5]={{-0.11229, -0.00559945,0.0537713,-0.0761336,-0.251},{-0.252351, -0.221315,-0.145954,-0.142887,-0.171631}};
double lamtildePX[2][5]={{-0.154163,-0.0607756,0.0155188,-0.206083,-0.236292},{-0.300599, -0.241242,-0.16235, -0.154,-0.182814}};
double cpmCentre[2][5]={{6.61274, 14.9849, 24.5775, 34.4264, 46.9469},{6.95899, 15.2337, 24.6783, 34.4796, 46.9283}};
Double_t cpmRange[NXBINS+1] = {0, 10, 20, 30, 40, 60};

for(int pt = 0; pt < 3; pt++) {
for(int cpm = 0; cpm < 5; cpm++) {
cpmcenter[cpm] = cpmCentre[pt][cpm];
cpmlow[cpm]=TMath::Abs(cpmCentre[ptBin-1][cpmBin-1]-cpmRange[cpmBin-1]);
cpmhigh[cpm]=TMath::Abs(cpmCentre[ptBin-1][cpmBin-1]-cpmRange[cpmBin]);

lmean[pt]=lamtildeCS[pt][cpm]-lamtildeHX[pt][cpm];
//lmean[pt]=lamtildeHX[rapBin-1][pt]-lamtildePX[rapBin-1][pt];
//lmean[pt]=lamtildePX[rapBin-1][pt]-lamtildeCS[rapBin-1][pt];
			
lmean[cpm]=DltildeCS_lmean[pt][cpm]-DltildeHX_lmean[pt][cpm];
//lmean[cpm]=DltildeHX_lmean[pt][cpm]-DltildePX_lmean[pt][cpm];
//lmean[cpm]=DltildePX_lmean[pt][cpm]-DltildeCS_lmean[pt][cpm];
}
}
TGraphAsymmErrors *ChangedGraph = new TGraphAsymmErrors(nBinscpm,cpmcenter,lmean,cpmlow,cpmhigh,0,0);

ChangedGraph->Draw("alp");
}