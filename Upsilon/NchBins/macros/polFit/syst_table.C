#include<iomanip>

int syst_table()
{

std::cout << std::fixed;
std::cout << std::setprecision(3);

////for BG syst
cout<<"BG systematics"<<endl;
for(int state = 0; state < 3; state++)
 {
   cout<<"Upsilon state = "<<state+1<<endl;
   if(state == 0) TFile f("Systematics/cutNPriVtx_BGsyst/cutNPriVtx_fLSB100_TO_cutNPriVtx_fLSB44/TGraphResults_1SUps.root");
   if(state == 1) TFile f("Systematics/cutNPriVtx_BGsyst/cutNPriVtx_fLSB74_TO_cutNPriVtx_fLSB18/TGraphResults_2SUps.root");
   if(state == 2) TFile f("Systematics/cutNPriVtx_BGsyst/cutNPriVtx_fLSB59_TO_cutNPriVtx_fLSB2/TGraphResults_3SUps.root");
   
  for(int pt = 1; pt < 3; pt++)
   {
     if(pt == 1) cout<<"Low pT bin"<<endl;
     if(pt == 2) cout<<"High pT bin"<<endl;
     
     int cpmrange[6]={0,10,20,30,40,60};
     
     if(state == 0) double cpmCentre[2][5]={{6.60749, 14.9818, 24.5746, 34.4256, 46.9465},{6.9573, 15.2325, 24.6739, 34.4821, 46.9327}};
     if(state == 1) double cpmCentre[2][5]={{6.55258, 15.0001, 24.5743, 34.4049, 46.824},{6.9774, 15.2256, 24.7153, 34.5299, 46.8986}};
     if(state == 2) double cpmCentre[2][5]={{6.52592, 14.9239, 24.5347, 34.3604, 46.9122},{6.89134, 15.1033, 24.6676, 34.3945, 46.9769}};
     
     if(state == 2 && pt == 1) {
     double cpmCentre[2][4]={{6.52592, 14.9239, 24.5347, 39.1154},{6.89134, 15.1033, 24.6676, 39.2905}};
     
     int cpmrange[6]={0,10,20,30,60};
     }
     
     int cpmmax = 5;     
     if(state == 2 && pt == 1) cpmmax = 4;
     for(int cpm = 0; cpm < cpmmax; cpm++)
     {
       char lthhisto[200];
       char lphhisto[200];
       char ltphisto[200];
       char ltildehisto[200];

		if(pt == 1){
		cout<<cpmrange[cpm]<<"--"<<cpmrange[cpm+1]<<" & $"<<lth_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<lph_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltp_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltilde_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<"\\\\"<<endl;
		}
		
		if(pt == 2){
		cout<<cpmrange[cpm]<<"--"<<cpmrange[cpm+1]<<" & $"<<lth_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<lph_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltp_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltilde_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<"\\\\"<<endl;
		}
     }
     cout<<endl;
   }
  }
  
////for Framework 1 syst
cout<<"For Framework 1 syst"<<endl;
for(int state = 0; state < 3; state++)
 {
   cout<<"Upsilon state = "<<state+1<<endl;
   if(state == 0) TFile f("Systematics/cutNPriVtx/cutNPriVtx_FrameworkI/ChangedTGraph/TGraphResults_1SUps.root");
   if(state == 1) TFile f("Systematics/cutNPriVtx/cutNPriVtx_FrameworkI/ChangedTGraph/TGraphResults_2SUps.root");
   if(state == 2) TFile f("Systematics/cutNPriVtx/cutNPriVtx_FrameworkI/ChangedTGraph/TGraphResults_3SUps.root");
   
  for(int pt = 1; pt < 3; pt++)
   {
     if(pt == 1) cout<<"Low pT bin"<<endl;
     if(pt == 2) cout<<"High pT bin"<<endl;
     
     int cpmrange[6]={0,10,20,30,40,60};
     
     if(state == 0) double cpmCentre[2][5]={{6.60749, 14.9818, 24.5746, 34.4256, 46.9465},{6.9573, 15.2325, 24.6739, 34.4821, 46.9327}};
     if(state == 1) double cpmCentre[2][5]={{6.55258, 15.0001, 24.5743, 34.4049, 46.824},{6.9774, 15.2256, 24.7153, 34.5299, 46.8986}};
     if(state == 2) double cpmCentre[2][5]={{6.52592, 14.9239, 24.5347, 34.3604, 46.9122},{6.89134, 15.1033, 24.6676, 34.3945, 46.9769}};
     
     if(state == 2 && pt == 1) {
     double cpmCentre[2][4]={{6.52592, 14.9239, 24.5347, 39.1154},{6.89134, 15.1033, 24.6676, 39.2905}};
     
     int cpmrange[6]={0,10,20,30,60};
     }
     
     int cpmmax = 5;     
     if(state == 2 && pt == 1) cpmmax = 4;
     for(int cpm = 0; cpm < cpmmax; cpm++)
     {
       char lthhisto[200];
       char lphhisto[200];
       char ltphisto[200];
       char ltildehisto[200];

		if(pt == 1){
		cout<<cpmrange[cpm]<<"--"<<cpmrange[cpm+1]<<" & $"<<lth_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<lph_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltp_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltilde_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<"\\\\"<<endl;
		}
		
		if(pt == 2){
		cout<<cpmrange[cpm]<<"--"<<cpmrange[cpm+1]<<" & $"<<lth_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<lph_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltp_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltilde_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<"\\\\"<<endl;
		}
     }
     cout<<endl;
   }
  }
  
////for Framework II syst
cout<<"For Framework II syst"<<endl;
for(int state = 0; state < 3; state++)
 {
   cout<<"Upsilon state = "<<state+1<<endl;
   if(state == 0) TFile f("Systematics/cutNPriVtx/cutNPriVtx_FrameworkII/ChangedTGraph/TGraphResults_1SUps.root");
   if(state == 1) TFile f("Systematics/cutNPriVtx/cutNPriVtx_FrameworkII/ChangedTGraph/TGraphResults_2SUps.root");
   if(state == 2) TFile f("Systematics/cutNPriVtx/cutNPriVtx_FrameworkII/ChangedTGraph/TGraphResults_3SUps.root");
   
  for(int pt = 1; pt < 3; pt++)
   {
     if(pt == 1) cout<<"Low pT bin"<<endl;
     if(pt == 2) cout<<"High pT bin"<<endl;
     
     int cpmrange[6]={0,10,20,30,40,60};
     
     if(state == 0) double cpmCentre[2][5]={{6.60749, 14.9818, 24.5746, 34.4256, 46.9465},{6.9573, 15.2325, 24.6739, 34.4821, 46.9327}};
     if(state == 1) double cpmCentre[2][5]={{6.55258, 15.0001, 24.5743, 34.4049, 46.824},{6.9774, 15.2256, 24.7153, 34.5299, 46.8986}};
     if(state == 2) double cpmCentre[2][5]={{6.52592, 14.9239, 24.5347, 34.3604, 46.9122},{6.89134, 15.1033, 24.6676, 34.3945, 46.9769}};
     
     if(state == 2 && pt == 1) {
     double cpmCentre[2][4]={{6.52592, 14.9239, 24.5347, 39.1154},{6.89134, 15.1033, 24.6676, 39.2905}};
     
     int cpmrange[6]={0,10,20,30,60};
     }
     
     int cpmmax = 5;     
     if(state == 2 && pt == 1) cpmmax = 4;
     for(int cpm = 0; cpm < cpmmax; cpm++)
     {
       char lthhisto[200];
       char lphhisto[200];
       char ltphisto[200];
       char ltildehisto[200];

		if(pt == 1){
		cout<<cpmrange[cpm]<<"--"<<cpmrange[cpm+1]<<" & $"<<lth_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<lph_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltp_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltilde_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<"\\\\"<<endl;
		}
		
		if(pt == 2){
		cout<<cpmrange[cpm]<<"--"<<cpmrange[cpm+1]<<" & $"<<lth_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<lph_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltp_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltilde_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<"\\\\"<<endl;
		}
     }
     cout<<endl;
   }
  }
  
////for Framework III syst
cout<<"For Framework III syst"<<endl;
for(int state = 0; state < 3; state++)
 {
   cout<<"Upsilon state = "<<state+1<<endl;
   if(state == 0) TFile f("Systematics/cutNPriVtx/cutNPriVtx_FrameworkIII/ChangedTGraph/TGraphResults_1SUps.root");
   if(state == 1) TFile f("Systematics/cutNPriVtx/cutNPriVtx_FrameworkIII/ChangedTGraph/TGraphResults_2SUps.root");
   if(state == 2) TFile f("Systematics/cutNPriVtx/cutNPriVtx_FrameworkIII/ChangedTGraph/TGraphResults_3SUps.root");
   
  for(int pt = 1; pt < 3; pt++)
   {
     if(pt == 1) cout<<"Low pT bin"<<endl;
     if(pt == 2) cout<<"High pT bin"<<endl;
     
     int cpmrange[6]={0,10,20,30,40,60};
     
     if(state == 0) double cpmCentre[2][5]={{6.60749, 14.9818, 24.5746, 34.4256, 46.9465},{6.9573, 15.2325, 24.6739, 34.4821, 46.9327}};
     if(state == 1) double cpmCentre[2][5]={{6.55258, 15.0001, 24.5743, 34.4049, 46.824},{6.9774, 15.2256, 24.7153, 34.5299, 46.8986}};
     if(state == 2) double cpmCentre[2][5]={{6.52592, 14.9239, 24.5347, 34.3604, 46.9122},{6.89134, 15.1033, 24.6676, 34.3945, 46.9769}};
     
     if(state == 2 && pt == 1) {
     double cpmCentre[2][4]={{6.52592, 14.9239, 24.5347, 39.1154},{6.89134, 15.1033, 24.6676, 39.2905}};
     
     int cpmrange[6]={0,10,20,30,60};
     }
     
     int cpmmax = 5;     
     if(state == 2 && pt == 1) cpmmax = 4;
     for(int cpm = 0; cpm < cpmmax; cpm++)
     {
       char lthhisto[200];
       char lphhisto[200];
       char ltphisto[200];
       char ltildehisto[200];

		if(pt == 1){
		cout<<cpmrange[cpm]<<"--"<<cpmrange[cpm+1]<<" & $"<<lth_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<lph_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltp_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltilde_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<"\\\\"<<endl;
		}
		
		if(pt == 2){
		cout<<cpmrange[cpm]<<"--"<<cpmrange[cpm+1]<<" & $"<<lth_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<lph_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltp_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltilde_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<"\\\\"<<endl;
		}
     }
     cout<<endl;
   }
  }
  
////for Parametrization syst
cout<<"For Parametrization syst"<<endl;
for(int state = 0; state < 3; state++)
 {
   cout<<"Upsilon state = "<<state+1<<endl;
   if(state == 0) TFile f("Systematics/cutNPriVtx/cutNPriVtx_Parametrization/ChangedTGraph/TGraphResults_1SUps.root");
   if(state == 1) TFile f("Systematics/cutNPriVtx/cutNPriVtx_Parametrization/ChangedTGraph/TGraphResults_2SUps.root");
   if(state == 2) TFile f("Systematics/cutNPriVtx/cutNPriVtx_Parametrization/ChangedTGraph/TGraphResults_3SUps.root");
   
  for(int pt = 1; pt < 3; pt++)
   {
     if(pt == 1) cout<<"Low pT bin"<<endl;
     if(pt == 2) cout<<"High pT bin"<<endl;
     
     int cpmrange[6]={0,10,20,30,40,60};
     
     if(state == 0) double cpmCentre[2][5]={{6.60749, 14.9818, 24.5746, 34.4256, 46.9465},{6.9573, 15.2325, 24.6739, 34.4821, 46.9327}};
     if(state == 1) double cpmCentre[2][5]={{6.55258, 15.0001, 24.5743, 34.4049, 46.824},{6.9774, 15.2256, 24.7153, 34.5299, 46.8986}};
     if(state == 2) double cpmCentre[2][5]={{6.52592, 14.9239, 24.5347, 34.3604, 46.9122},{6.89134, 15.1033, 24.6676, 34.3945, 46.9769}};
     
     if(state == 2 && pt == 1) {
     double cpmCentre[2][4]={{6.52592, 14.9239, 24.5347, 39.1154},{6.89134, 15.1033, 24.6676, 39.2905}};
     
     int cpmrange[6]={0,10,20,30,60};
     }
     
     int cpmmax = 5;     
     if(state == 2 && pt == 1) cpmmax = 4;
     for(int cpm = 0; cpm < cpmmax; cpm++)
     {
       char lthhisto[200];
       char lphhisto[200];
       char ltphisto[200];
       char ltildehisto[200];

		if(pt == 1){
		cout<<cpmrange[cpm]<<"--"<<cpmrange[cpm+1]<<" & $"<<lth_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<lph_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltp_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltilde_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<"\\\\"<<endl;
		}
		
		if(pt == 2){
		cout<<cpmrange[cpm]<<"--"<<cpmrange[cpm+1]<<" & $"<<lth_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<lph_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltp_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltilde_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<"\\\\"<<endl;
		}
     }
     cout<<endl;
   }
  }
  
////for Rho factor syst
cout<<"For Rho factor syst"<<endl;
for(int state = 0; state < 3; state++)
 {
   cout<<"Upsilon state = "<<state+1<<endl;
   if(state == 0) TFile f("Systematics/cutNPriVtx/cutNPriVtx_RhoFactor/ChangedTGraph/TGraphResults_1SUps.root");
   if(state == 1) TFile f("Systematics/cutNPriVtx/cutNPriVtx_RhoFactor/ChangedTGraph/TGraphResults_2SUps.root");
   if(state == 2) TFile f("Systematics/cutNPriVtx/cutNPriVtx_RhoFactor/ChangedTGraph/TGraphResults_3SUps.root");
   
  for(int pt = 1; pt < 3; pt++)
   {
     if(pt == 1) cout<<"Low pT bin"<<endl;
     if(pt == 2) cout<<"High pT bin"<<endl;
     
     int cpmrange[6]={0,10,20,30,40,60};
     
     if(state == 0) double cpmCentre[2][5]={{6.60749, 14.9818, 24.5746, 34.4256, 46.9465},{6.9573, 15.2325, 24.6739, 34.4821, 46.9327}};
     if(state == 1) double cpmCentre[2][5]={{6.55258, 15.0001, 24.5743, 34.4049, 46.824},{6.9774, 15.2256, 24.7153, 34.5299, 46.8986}};
     if(state == 2) double cpmCentre[2][5]={{6.52592, 14.9239, 24.5347, 34.3604, 46.9122},{6.89134, 15.1033, 24.6676, 34.3945, 46.9769}};
     
     if(state == 2 && pt == 1) {
     double cpmCentre[2][4]={{6.52592, 14.9239, 24.5347, 39.1154},{6.89134, 15.1033, 24.6676, 39.2905}};
     
     int cpmrange[6]={0,10,20,30,60};
     }
     
     int cpmmax = 5;     
     if(state == 2 && pt == 1) cpmmax = 4;
     for(int cpm = 0; cpm < cpmmax; cpm++)
     {
       char lthhisto[200];
       char lphhisto[200];
       char ltphisto[200];
       char ltildehisto[200];

		if(pt == 1){
		cout<<cpmrange[cpm]<<"--"<<cpmrange[cpm+1]<<" & $"<<lth_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<lph_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltp_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltilde_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<"\\\\"<<endl;
		}
		
		if(pt == 2){
		cout<<cpmrange[cpm]<<"--"<<cpmrange[cpm+1]<<" & $"<<lth_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<lph_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltp_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltilde_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<"\\\\"<<endl;
		}
     }
     cout<<endl;
   }
  }
  
////for TnP Model syst
cout<<"For TnP Model syst"<<endl;
for(int state = 0; state < 3; state++)
 {
   cout<<"Upsilon state = "<<state+1<<endl;
   if(state == 0) TFile f("Systematics/cutNPriVtx/cutNPriVtx_TnP_model/ChangedTGraph/TGraphResults_1SUps.root");
   if(state == 1) TFile f("Systematics/cutNPriVtx/cutNPriVtx_TnP_model/ChangedTGraph/TGraphResults_2SUps.root");
   if(state == 2) TFile f("Systematics/cutNPriVtx/cutNPriVtx_TnP_model/ChangedTGraph/TGraphResults_3SUps.root");
   
  for(int pt = 1; pt < 3; pt++)
   {
     if(pt == 1) cout<<"Low pT bin"<<endl;
     if(pt == 2) cout<<"High pT bin"<<endl;
     
     int cpmrange[6]={0,10,20,30,40,60};
     
     if(state == 0) double cpmCentre[2][5]={{6.60749, 14.9818, 24.5746, 34.4256, 46.9465},{6.9573, 15.2325, 24.6739, 34.4821, 46.9327}};
     if(state == 1) double cpmCentre[2][5]={{6.55258, 15.0001, 24.5743, 34.4049, 46.824},{6.9774, 15.2256, 24.7153, 34.5299, 46.8986}};
     if(state == 2) double cpmCentre[2][5]={{6.52592, 14.9239, 24.5347, 34.3604, 46.9122},{6.89134, 15.1033, 24.6676, 34.3945, 46.9769}};
     
     if(state == 2 && pt == 1) {
     double cpmCentre[2][4]={{6.52592, 14.9239, 24.5347, 39.1154},{6.89134, 15.1033, 24.6676, 39.2905}};
     
     int cpmrange[6]={0,10,20,30,60};
     }
     
     int cpmmax = 5;     
     if(state == 2 && pt == 1) cpmmax = 4;
     for(int cpm = 0; cpm < cpmmax; cpm++)
     {
       char lthhisto[200];
       char lphhisto[200];
       char ltphisto[200];
       char ltildehisto[200];

		if(pt == 1){
		cout<<cpmrange[cpm]<<"--"<<cpmrange[cpm+1]<<" & $"<<lth_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<lph_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltp_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltilde_PX_rap1_pt1->Eval(cpmCentre[pt-1][cpm])<<"\\\\"<<endl;
		}
		
		if(pt == 2){
		cout<<cpmrange[cpm]<<"--"<<cpmrange[cpm+1]<<" & $"<<lth_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<lph_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltp_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<" $ & $ "<<ltilde_PX_rap1_pt2->Eval(cpmCentre[pt-1][cpm])<<"\\\\"<<endl;
		}
     }
     cout<<endl;
   }
  }
  
  }