{
char nameCMS1S[500], nameCMS2S[500], nameCMS3S[500];
sprintf(nameCMS1S,"/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx_smallerpT2_FinalSyst_Glob/TGraphResults_1SUps.root");
sprintf(nameCMS2S,"/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx_smallerpT2_FinalSyst_Glob/TGraphResults_2SUps.root");
sprintf(nameCMS3S,"/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx_smallerpT2_FinalSyst_Glob/TGraphResults_3SUps.root");	
TFile *fileCMS1S   = new TFile(nameCMS1S,"R");
TFile *fileCMS2S   = new TFile(nameCMS2S,"R");
TFile *fileCMS3S   = new TFile(nameCMS3S,"R");
TMultiGraph 	   *merged1S = new TMultiGraph();
TMultiGraph		   *merged2S = new TMultiGraph();
TMultiGraph 	   *merged3S = new TMultiGraph();

TGraph *pt1 = (TGraph*)fileCMS1S->Get("lth_HX_rap1_pt1");
TGraph *pt2 = (TGraph*)fileCMS1S->Get("lth_HX_rap1_pt2");
merged1S->Add(pt1);
merged1S->Add(pt2);
TGraph *pt1 = (TGraph*)fileCMS2S->Get("lth_HX_rap1_pt1");
TGraph *pt2 = (TGraph*)fileCMS2S->Get("lth_HX_rap1_pt2");
merged2S->Add(pt1);
merged2S->Add(pt2);
TGraph *pt1 = (TGraph*)fileCMS3S->Get("lth_HX_rap1_pt1");
TGraph *pt2 = (TGraph*)fileCMS3S->Get("lth_HX_rap1_pt2");
merged3S->Add(pt1);
merged3S->Add(pt2);
    
char graphName[500];
sprintf(graphName,"lth_HX_rap1_pt2");









TF1* slope1slow = new TF1("slope1slow","pol1",0,30); ////1st order polynomial
TF1* slope1shigh = new TF1("slope1shigh","pol1",30,60); ////1st order polynomial
TF1* slope2slow = new TF1("slope2slow","pol1",0,30); ////1st order polynomial
TF1* slope2shigh = new TF1("slope2shigh","pol1",30,60); ////1st order polynomial
TF1* slope3slow = new TF1("slope3slow","pol1",0,30); ////1st order polynomial
TF1* slope3shigh = new TF1("slope3shigh","pol1",30,60); ////1st order polynomial

merged1S->Fit("slope1shigh","EFNR");
merged1S->Fit("slope1slow","EFNR");
merged2S->Fit("slope2shigh","EFNR");
merged2S->Fit("slope2slow","EFNR");
merged3S->Fit("slope3shigh","EFNR");
merged3S->Fit("slope3slow","EFNR");

double OneSslopelp0 = slope1slow->GetParameter(0);
double OneSslopelerr_p0 = slope1slow->GetParError(0);
double OneSslopelp1 = slope1slow->GetParameter(1);
double OneSslopelerr_p1 = slope1slow->GetParError(1);
double OneSslopehp0 = slope1shigh->GetParameter(0);
double OneSslopeherr_p0 = slope1shigh->GetParError(0);
double OneSslopehp1 = slope1shigh->GetParameter(1);
double OneSslopeherr_p1 = slope1shigh->GetParError(1);

double TwoSslopelp0 = slope2slow->GetParameter(0);
double TwoSslopelerr_p0 = slope2slow->GetParError(0);
double TwoSslopelp1 = slope2slow->GetParameter(1);
double TwoSslopelerr_p1 = slope2slow->GetParError(1);
double TwoSslopehp0 = slope2shigh->GetParameter(0);
double TwoSslopeherr_p0 = slope2shigh->GetParError(0);
double TwoSslopehp1 = slope2shigh->GetParameter(1);
double TwoSslopeherr_p1 = slope2shigh->GetParError(1);

double ThreeSslopelp0 = slope3slow->GetParameter(0);
double ThreeSslopelerr_p0 = slope3slow->GetParError(0);
double ThreeSslopelp1 = slope3slow->GetParameter(1);
double ThreeSslopelerr_p1 = slope3slow->GetParError(1);
double ThreeSslopehp0 = slope3shigh->GetParameter(0);
double ThreeSslopeherr_p0 = slope3shigh->GetParError(0);
double ThreeSslopehp1 = slope3shigh->GetParameter(1);
double ThreeSslopeherr_p1 = slope3shigh->GetParError(1);

double lam0_1s = OneSslopelp0;
double lam60_1s = OneSslopehp0+OneSslopehp1*60;
cout<<"lam min 1s = "<<lam0_1s<<" +- "<<OneSslopelerr_p0<<endl;
cout<<"lam max 1s = "<<lam60_1s<<endl;

double lam0_2s = TwoSslopelp0;
double lam60_2s = TwoSslopehp0+TwoSslopehp1*60;
cout<<"lam min 2s = "<<lam0_2s<<" +- "<<TwoSslopelerr_p0<<endl;
cout<<"lam max 2s = "<<lam60_2s<<endl;

double lam0_3s = ThreeSslopelp0;
double lam60_3s = ThreeSslopehp0+ThreeSslopehp1*60;
cout<<"lam min 3s = "<<lam0_3s<<" +- "<<ThreeSslopelerr_p0<<endl;
cout<<"lam max 3s = "<<lam60_3s<<endl;

double lamnewplus = 1;
double lamnewminus = -1;

double f_new1sPlus = ((lam60_1s-lam0_1s)*(3+lamnewplus))/ ((lamnewplus-lam0_1s)*(3+lam60_1s));
double f_new1sMinus =((lam60_1s-lam0_1s)*(3+lamnewminus))/ ((lamnewminus-lam0_1s)*(3+lam60_1s));

double f_new2sPlus = ((lam60_2s-lam0_2s)*(3+lamnewplus))/ ((lamnewplus-lam0_2s)*(3+lam60_2s));
double f_new2sMinus =((lam60_2s-lam0_2s)*(3+lamnewminus))/ ((lamnewminus-lam0_2s)*(3+lam60_2s));

double f_new3sPlus = ((lam60_3s-lam0_3s)*(3+lamnewplus))/ ((lamnewplus-lam0_3s)*(3+lam60_3s));
double f_new3sMinus =((lam60_3s-lam0_3s)*(3+lamnewminus))/ ((lamnewminus-lam0_3s)*(3+lam60_3s));

cout<<"f_new 1s plus one: "<<f_new1sPlus<<endl;
cout<<"f_new 1s minus one: "<<f_new1sMinus<<endl;
cout<<"f_new 2s plus one: "<<f_new2sPlus<<endl;
cout<<"f_new 2s minus one: "<<f_new2sMinus<<endl;
cout<<"f_new 3s plus one: "<<f_new3sPlus<<endl;
cout<<"f_new 3s minus one: "<<f_new3sMinus<<endl;
}