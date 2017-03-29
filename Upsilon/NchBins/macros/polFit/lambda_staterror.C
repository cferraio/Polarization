{

//double cpmCentre[2][5]={{6.60749, 14.9818, 24.5746, 34.4256, 46.9465},{6.9573, 15.2325, 24.6739, 34.4821, 46.9327}};
double cpmCentre[2][5]={{6.55258, 15.0001, 24.5743, 34.4049, 46.824},{6.9774, 15.2256, 24.7153, 34.5299, 46.8986}};
//double cpmCentre[2][5]={{6.52592, 14.9239, 24.5347, 34.3604, 46.9122},{6.89134, 15.1033, 24.6676, 34.3945, 46.9769}};
//double cpmCentre[2][4]={{6.52592, 14.9239, 24.5347, 39.1154},{6.89134, 15.1033, 24.6676, 39.2905}};

//this first part is for lambda values and total uncertainties for tables 4-6 and delta tilde plot
//the second part is for total systematics, for tables 8-10

//#if 0
 TFile f("/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx_withsys/TGraphResults_2SUps.root");
 


cout<<"CS"<<endl<<endl;

for(int cpm = 0; cpm < 4; cpm++)
{
cout<<"0--10 & $"<<lth_CS_rap1_pt1->Eval(cpmCentre[0][cpm])<<"_{-"<<lth_CS_rap1_pt1->GetErrorYlow(cpm)<<"}^{+"<<lth_CS_rap1_pt1->GetErrorYhigh(cpm)<<"}$&$"<<lph_CS_rap1_pt1->Eval(cpmCentre[0][cpm])<<"_{-"<<lph_CS_rap1_pt1->GetErrorYlow(cpm)<<"}^{+"<<lph_CS_rap1_pt1->GetErrorYhigh(cpm)<<"}$&$"<<ltp_CS_rap1_pt1->Eval(cpmCentre[0][cpm])<<"_{-"<<ltp_CS_rap1_pt1->GetErrorYlow(cpm)<<"}^{+"<<ltp_CS_rap1_pt1->GetErrorYhigh(cpm)<<"}$&$"<<ltilde_CS_rap1_pt1->Eval(cpmCentre[0][cpm])<<"_{-"<<ltilde_CS_rap1_pt1->GetErrorYlow(cpm)<<"}^{+"<<ltilde_CS_rap1_pt1->GetErrorYhigh(cpm)<<"}$\\\\"<<endl;
}
cout<<endl;
for(int cpm = 0; cpm < 5; cpm++)
{
cout<<"0--10 & $"<<lth_CS_rap1_pt2->Eval(cpmCentre[1][cpm])<<"_{-"<<lth_CS_rap1_pt2->GetErrorYlow(cpm)<<"}^{+"<<lth_CS_rap1_pt2->GetErrorYhigh(cpm)<<"}$&$"<<lph_CS_rap1_pt2->Eval(cpmCentre[1][cpm])<<"_{-"<<lph_CS_rap1_pt2->GetErrorYlow(cpm)<<"}^{+"<<lph_CS_rap1_pt2->GetErrorYhigh(cpm)<<"}$&$"<<ltp_CS_rap1_pt2->Eval(cpmCentre[1][cpm])<<"_{-"<<ltp_CS_rap1_pt2->GetErrorYlow(cpm)<<"}^{+"<<ltp_CS_rap1_pt2->GetErrorYhigh(cpm)<<"}$&$"<<ltilde_CS_rap1_pt2->Eval(cpmCentre[1][cpm])<<"_{-"<<ltilde_CS_rap1_pt2->GetErrorYlow(cpm)<<"}^{+"<<ltilde_CS_rap1_pt2->GetErrorYhigh(cpm)<<"}$\\\\"<<endl;
}



cout<<"PX"<<endl<<endl;
for(int cpm = 0; cpm < 4; cpm++)
{
cout<<"0--10 & $"<<lth_PX_rap1_pt1->Eval(cpmCentre[0][cpm])<<"_{-"<<lth_PX_rap1_pt1->GetErrorYlow(cpm)<<"}^{+"<<lth_PX_rap1_pt1->GetErrorYhigh(cpm)<<"}$&$"<<lph_PX_rap1_pt1->Eval(cpmCentre[0][cpm])<<"_{-"<<lph_PX_rap1_pt1->GetErrorYlow(cpm)<<"}^{+"<<lph_PX_rap1_pt1->GetErrorYhigh(cpm)<<"}$&$"<<ltp_PX_rap1_pt1->Eval(cpmCentre[0][cpm])<<"_{-"<<ltp_PX_rap1_pt1->GetErrorYlow(cpm)<<"}^{+"<<ltp_PX_rap1_pt1->GetErrorYhigh(cpm)<<"}$&$"<<ltilde_PX_rap1_pt1->Eval(cpmCentre[0][cpm])<<"_{-"<<ltilde_PX_rap1_pt1->GetErrorYlow(cpm)<<"}^{+"<<ltilde_PX_rap1_pt1->GetErrorYhigh(cpm)<<"}$\\\\"<<endl;
}
cout<<endl;
/*for(int cpm = 0; cpm < 5; cpm++)
{
cout<<"0--10 & $"<<lth_PX_rap1_pt2->Eval(cpmCentre[1][cpm])<<"_{-"<<lth_PX_rap1_pt2->GetErrorYlow(cpm)<<"}^{+"<<lth_PX_rap1_pt2->GetErrorYhigh(cpm)<<"}$&$"<<lph_PX_rap1_pt2->Eval(cpmCentre[1][cpm])<<"_{-"<<lph_PX_rap1_pt2->GetErrorYlow(cpm)<<"}^{+"<<lph_PX_rap1_pt2->GetErrorYhigh(cpm)<<"}$&$"<<ltp_PX_rap1_pt2->Eval(cpmCentre[1][cpm])<<"_{-"<<ltp_PX_rap1_pt2->GetErrorYlow(cpm)<<"}^{+"<<ltp_PX_rap1_pt2->GetErrorYhigh(cpm)<<"}$&$"<<ltilde_PX_rap1_pt2->Eval(cpmCentre[1][cpm])<<"_{-"<<ltilde_PX_rap1_pt2->GetErrorYlow(cpm)<<"}^{+"<<ltilde_PX_rap1_pt2->GetErrorYhigh(cpm)<<"}$\\\\"<<endl;
}
*/


cout<<"HX"<<endl<<endl;
for(int cpm = 0; cpm < 4; cpm++)
{
cout<<"0--10 & $"<<lth_HX_rap1_pt1->Eval(cpmCentre[0][cpm])<<"_{-"<<lth_HX_rap1_pt1->GetErrorYlow(cpm)<<"}^{+"<<lth_HX_rap1_pt1->GetErrorYhigh(cpm)<<"}$&$"<<lph_HX_rap1_pt1->Eval(cpmCentre[0][cpm])<<"_{-"<<lph_HX_rap1_pt1->GetErrorYlow(cpm)<<"}^{+"<<lph_HX_rap1_pt1->GetErrorYhigh(cpm)<<"}$&$"<<ltp_HX_rap1_pt1->Eval(cpmCentre[0][cpm])<<"_{-"<<ltp_HX_rap1_pt1->GetErrorYlow(cpm)<<"}^{+"<<ltp_HX_rap1_pt1->GetErrorYhigh(cpm)<<"}$&$"<<ltilde_HX_rap1_pt1->Eval(cpmCentre[0][cpm])<<"_{-"<<ltilde_HX_rap1_pt1->GetErrorYlow(cpm)<<"}^{+"<<ltilde_HX_rap1_pt1->GetErrorYhigh(cpm)<<"}$\\\\"<<endl;
}
cout<<endl;
cout<<endl;
/*
for(int cpm = 0; cpm < 5; cpm++)
{
cout<<"0--10 & $"<<lth_HX_rap1_pt2->Eval(cpmCentre[1][cpm])<<"_{-"<<lth_HX_rap1_pt2->GetErrorYlow(cpm)<<"}^{+"<<lth_HX_rap1_pt2->GetErrorYhigh(cpm)<<"}$&$"<<lph_HX_rap1_pt2->Eval(cpmCentre[1][cpm])<<"_{-"<<lph_HX_rap1_pt2->GetErrorYlow(cpm)<<"}^{+"<<lph_HX_rap1_pt2->GetErrorYhigh(cpm)<<"}$&$"<<ltp_HX_rap1_pt2->Eval(cpmCentre[1][cpm])<<"_{-"<<ltp_HX_rap1_pt2->GetErrorYlow(cpm)<<"}^{+"<<ltp_HX_rap1_pt2->GetErrorYhigh(cpm)<<"}$&$"<<ltilde_HX_rap1_pt2->Eval(cpmCentre[1][cpm])<<"_{-"<<ltilde_HX_rap1_pt2->GetErrorYlow(cpm)<<"}^{+"<<ltilde_HX_rap1_pt2->GetErrorYhigh(cpm)<<"}$\\\\"<<endl;
}

*/

//#endif



TFile f("Systematics/cutNPriVtx/AverageSyst/TGraphResults_3SUps.root");

#if 0
cout<<"CS"<<endl<<endl;
/*cout<<" 0--10 & $ "<<lth_CS_rap1_pt1->Eval(cpmCentre[0][0])<<" $ & $ "<<lph_CS_rap1_pt1->Eval(cpmCentre[0][0])<<" $ & $ "<<ltp_CS_rap1_pt1->Eval(cpmCentre[0][0])<<" $ & $ "<<ltilde_CS_rap1_pt1->Eval(cpmCentre[0][0])<<" $ \\\\"<<endl;
cout<<"10--20 & $ "<<lth_CS_rap1_pt1->Eval(cpmCentre[0][1])<<" $ & $ "<<lph_CS_rap1_pt1->Eval(cpmCentre[0][1])<<" $ & $ "<<ltp_CS_rap1_pt1->Eval(cpmCentre[0][1])<<" $ & $ "<<ltilde_CS_rap1_pt1->Eval(cpmCentre[0][1])<<" $ \\\\"<<endl;
cout<<"20--30 & $ "<<lth_CS_rap1_pt1->Eval(cpmCentre[0][2])<<" $ & $ "<<lph_CS_rap1_pt1->Eval(cpmCentre[0][2])<<" $ & $ "<<ltp_CS_rap1_pt1->Eval(cpmCentre[0][2])<<" $ & $ "<<ltilde_CS_rap1_pt1->Eval(cpmCentre[0][2])<<" $ \\\\"<<endl;
cout<<"30--40 & $ "<<lth_CS_rap1_pt1->Eval(cpmCentre[0][3])<<" $ & $ "<<lph_CS_rap1_pt1->Eval(cpmCentre[0][3])<<" $ & $ "<<ltp_CS_rap1_pt1->Eval(cpmCentre[0][3])<<" $ & $ "<<ltilde_CS_rap1_pt1->Eval(cpmCentre[0][3])<<" $ \\\\"<<endl;
cout<<"40--60 & $ "<<lth_CS_rap1_pt1->Eval(cpmCentre[0][4])<<" $ & $ "<<lph_CS_rap1_pt1->Eval(cpmCentre[0][4])<<" $ & $ "<<ltp_CS_rap1_pt1->Eval(cpmCentre[0][4])<<" $ & $ "<<ltilde_CS_rap1_pt1->Eval(cpmCentre[0][4])<<" $ \\\\"<<endl;
cout<<endl;*/
cout<<" 0--10 & $ "<<lth_CS_rap1_pt2->Eval(cpmCentre[1][0])<<" $ & $ "<<lph_CS_rap1_pt2->Eval(cpmCentre[1][0])<<" $ & $ "<<ltp_CS_rap1_pt2->Eval(cpmCentre[1][0])<<" $ & $ "<<ltilde_CS_rap1_pt2->Eval(cpmCentre[1][0])<<" $ \\\\"<<endl;
cout<<"10--20 & $ "<<lth_CS_rap1_pt2->Eval(cpmCentre[1][1])<<" $ & $ "<<lph_CS_rap1_pt2->Eval(cpmCentre[1][1])<<" $ & $ "<<ltp_CS_rap1_pt2->Eval(cpmCentre[1][1])<<" $ & $ "<<ltilde_CS_rap1_pt2->Eval(cpmCentre[1][1])<<" $ \\\\"<<endl;
cout<<"20--30 & $ "<<lth_CS_rap1_pt2->Eval(cpmCentre[1][2])<<" $ & $ "<<lph_CS_rap1_pt2->Eval(cpmCentre[1][2])<<" $ & $ "<<ltp_CS_rap1_pt2->Eval(cpmCentre[1][2])<<" $ & $ "<<ltilde_CS_rap1_pt2->Eval(cpmCentre[1][2])<<" $ \\\\"<<endl;
cout<<"30--40 & $ "<<lth_CS_rap1_pt2->Eval(cpmCentre[1][3])<<" $ & $ "<<lph_CS_rap1_pt2->Eval(cpmCentre[1][3])<<" $ & $ "<<ltp_CS_rap1_pt2->Eval(cpmCentre[1][3])<<" $ & $ "<<ltilde_CS_rap1_pt2->Eval(cpmCentre[1][3])<<" $ \\\\"<<endl;
cout<<"40--60 & $ "<<lth_CS_rap1_pt2->Eval(cpmCentre[1][4])<<" $ & $ "<<lph_CS_rap1_pt2->Eval(cpmCentre[1][4])<<" $ & $ "<<ltp_CS_rap1_pt2->Eval(cpmCentre[1][4])<<" $ & $ "<<ltilde_CS_rap1_pt2->Eval(cpmCentre[1][4])<<" $ \\\\"<<endl;


cout<<"HX"<<endl<<endl;
/*cout<<" 0--10 & $ "<<lth_HX_rap1_pt1->Eval(cpmCentre[0][0])<<" $ & $ "<<lph_HX_rap1_pt1->Eval(cpmCentre[0][0])<<" $ & $ "<<ltp_HX_rap1_pt1->Eval(cpmCentre[0][0])<<" $ & $ "<<ltilde_HX_rap1_pt1->Eval(cpmCentre[0][0])<<" $ \\\\"<<endl;
cout<<"10--20 & $ "<<lth_HX_rap1_pt1->Eval(cpmCentre[0][1])<<" $ & $ "<<lph_HX_rap1_pt1->Eval(cpmCentre[0][1])<<" $ & $ "<<ltp_HX_rap1_pt1->Eval(cpmCentre[0][1])<<" $ & $ "<<ltilde_HX_rap1_pt1->Eval(cpmCentre[0][1])<<" $ \\\\"<<endl;
cout<<"20--30 & $ "<<lth_HX_rap1_pt1->Eval(cpmCentre[0][2])<<" $ & $ "<<lph_HX_rap1_pt1->Eval(cpmCentre[0][2])<<" $ & $ "<<ltp_HX_rap1_pt1->Eval(cpmCentre[0][2])<<" $ & $ "<<ltilde_HX_rap1_pt1->Eval(cpmCentre[0][2])<<" $ \\\\"<<endl;
cout<<"30--40 & $ "<<lth_HX_rap1_pt1->Eval(cpmCentre[0][3])<<" $ & $ "<<lph_HX_rap1_pt1->Eval(cpmCentre[0][3])<<" $ & $ "<<ltp_HX_rap1_pt1->Eval(cpmCentre[0][3])<<" $ & $ "<<ltilde_HX_rap1_pt1->Eval(cpmCentre[0][3])<<" $ \\\\"<<endl;
cout<<"40--60 & $ "<<lth_HX_rap1_pt1->Eval(cpmCentre[0][4])<<" $ & $ "<<lph_HX_rap1_pt1->Eval(cpmCentre[0][4])<<" $ & $ "<<ltp_HX_rap1_pt1->Eval(cpmCentre[0][4])<<" $ & $ "<<ltilde_HX_rap1_pt1->Eval(cpmCentre[0][4])<<" $ \\\\"<<endl;
cout<<endl; */
cout<<" 0--10 & $ "<<lth_HX_rap1_pt2->Eval(cpmCentre[1][0])<<" $ & $ "<<lph_HX_rap1_pt2->Eval(cpmCentre[1][0])<<" $ & $ "<<ltp_HX_rap1_pt2->Eval(cpmCentre[1][0])<<" $ & $ "<<ltilde_HX_rap1_pt2->Eval(cpmCentre[1][0])<<" $ \\\\"<<endl;
cout<<"10--20 & $ "<<lth_HX_rap1_pt2->Eval(cpmCentre[1][1])<<" $ & $ "<<lph_HX_rap1_pt2->Eval(cpmCentre[1][1])<<" $ & $ "<<ltp_HX_rap1_pt2->Eval(cpmCentre[1][1])<<" $ & $ "<<ltilde_HX_rap1_pt2->Eval(cpmCentre[1][1])<<" $ \\\\"<<endl;
cout<<"20--30 & $ "<<lth_HX_rap1_pt2->Eval(cpmCentre[1][2])<<" $ & $ "<<lph_HX_rap1_pt2->Eval(cpmCentre[1][2])<<" $ & $ "<<ltp_HX_rap1_pt2->Eval(cpmCentre[1][2])<<" $ & $ "<<ltilde_HX_rap1_pt2->Eval(cpmCentre[1][2])<<" $ \\\\"<<endl;
cout<<"30--40 & $ "<<lth_HX_rap1_pt2->Eval(cpmCentre[1][3])<<" $ & $ "<<lph_HX_rap1_pt2->Eval(cpmCentre[1][3])<<" $ & $ "<<ltp_HX_rap1_pt2->Eval(cpmCentre[1][3])<<" $ & $ "<<ltilde_HX_rap1_pt2->Eval(cpmCentre[1][3])<<" $ \\\\"<<endl;
cout<<"40--60 & $ "<<lth_HX_rap1_pt2->Eval(cpmCentre[1][4])<<" $ & $ "<<lph_HX_rap1_pt2->Eval(cpmCentre[1][4])<<" $ & $ "<<ltp_HX_rap1_pt2->Eval(cpmCentre[1][4])<<" $ & $ "<<ltilde_HX_rap1_pt2->Eval(cpmCentre[1][4])<<" $ \\\\"<<endl;

cout<<"PX"<<endl<<endl;
/*cout<<" 0--10 & $ "<<lth_PX_rap1_pt1->Eval(cpmCentre[0][0])<<" $ & $ "<<lph_PX_rap1_pt1->Eval(cpmCentre[0][0])<<" $ & $ "<<ltp_PX_rap1_pt1->Eval(cpmCentre[0][0])<<" $ & $ "<<ltilde_PX_rap1_pt1->Eval(cpmCentre[0][0])<<" $ \\\\"<<endl;
cout<<"10--20 & $ "<<lth_PX_rap1_pt1->Eval(cpmCentre[0][1])<<" $ & $ "<<lph_PX_rap1_pt1->Eval(cpmCentre[0][1])<<" $ & $ "<<ltp_PX_rap1_pt1->Eval(cpmCentre[0][1])<<" $ & $ "<<ltilde_PX_rap1_pt1->Eval(cpmCentre[0][1])<<" $ \\\\"<<endl;
cout<<"20--30 & $ "<<lth_PX_rap1_pt1->Eval(cpmCentre[0][2])<<" $ & $ "<<lph_PX_rap1_pt1->Eval(cpmCentre[0][2])<<" $ & $ "<<ltp_PX_rap1_pt1->Eval(cpmCentre[0][2])<<" $ & $ "<<ltilde_PX_rap1_pt1->Eval(cpmCentre[0][2])<<" $ \\\\"<<endl;
cout<<"30--40 & $ "<<lth_PX_rap1_pt1->Eval(cpmCentre[0][3])<<" $ & $ "<<lph_PX_rap1_pt1->Eval(cpmCentre[0][3])<<" $ & $ "<<ltp_PX_rap1_pt1->Eval(cpmCentre[0][3])<<" $ & $ "<<ltilde_PX_rap1_pt1->Eval(cpmCentre[0][3])<<" $ \\\\"<<endl;
cout<<"40--60 & $ "<<lth_PX_rap1_pt1->Eval(cpmCentre[0][4])<<" $ & $ "<<lph_PX_rap1_pt1->Eval(cpmCentre[0][4])<<" $ & $ "<<ltp_PX_rap1_pt1->Eval(cpmCentre[0][4])<<" $ & $ "<<ltilde_PX_rap1_pt1->Eval(cpmCentre[0][4])<<" $ \\\\"<<endl;
cout<<endl; */
cout<<" 0--10 & $ "<<lth_PX_rap1_pt2->Eval(cpmCentre[1][0])<<" $ & $ "<<lph_PX_rap1_pt2->Eval(cpmCentre[1][0])<<" $ & $ "<<ltp_PX_rap1_pt2->Eval(cpmCentre[1][0])<<" $ & $ "<<ltilde_PX_rap1_pt2->Eval(cpmCentre[1][0])<<" $ \\\\"<<endl;
cout<<"10--20 & $ "<<lth_PX_rap1_pt2->Eval(cpmCentre[1][1])<<" $ & $ "<<lph_PX_rap1_pt2->Eval(cpmCentre[1][1])<<" $ & $ "<<ltp_PX_rap1_pt2->Eval(cpmCentre[1][1])<<" $ & $ "<<ltilde_PX_rap1_pt2->Eval(cpmCentre[1][1])<<" $ \\\\"<<endl;
cout<<"20--30 & $ "<<lth_PX_rap1_pt2->Eval(cpmCentre[1][2])<<" $ & $ "<<lph_PX_rap1_pt2->Eval(cpmCentre[1][2])<<" $ & $ "<<ltp_PX_rap1_pt2->Eval(cpmCentre[1][2])<<" $ & $ "<<ltilde_PX_rap1_pt2->Eval(cpmCentre[1][2])<<" $ \\\\"<<endl;
cout<<"30--40 & $ "<<lth_PX_rap1_pt2->Eval(cpmCentre[1][3])<<" $ & $ "<<lph_PX_rap1_pt2->Eval(cpmCentre[1][3])<<" $ & $ "<<ltp_PX_rap1_pt2->Eval(cpmCentre[1][3])<<" $ & $ "<<ltilde_PX_rap1_pt2->Eval(cpmCentre[1][3])<<" $ \\\\"<<endl;
cout<<"40--60 & $ "<<lth_PX_rap1_pt2->Eval(cpmCentre[1][4])<<" $ & $ "<<lph_PX_rap1_pt2->Eval(cpmCentre[1][4])<<" $ & $ "<<ltp_PX_rap1_pt2->Eval(cpmCentre[1][4])<<" $ & $ "<<ltilde_PX_rap1_pt2->Eval(cpmCentre[1][4])<<" $ \\\\"<<endl;
#endif

cout<<"CS"<<endl<<endl;

cout<<" 0--10 & $ "<<lth_CS_rap1_pt1->Eval(cpmCentre[0][0])<<" $ & $ "<<lph_CS_rap1_pt1->Eval(cpmCentre[0][0])<<" $ & $ "<<ltp_CS_rap1_pt1->Eval(cpmCentre[0][0])<<" $ & $ "<<ltilde_CS_rap1_pt1->Eval(cpmCentre[0][0])<<" $ \\\\"<<endl;
cout<<"10--20 & $ "<<lth_CS_rap1_pt1->Eval(cpmCentre[0][1])<<" $ & $ "<<lph_CS_rap1_pt1->Eval(cpmCentre[0][1])<<" $ & $ "<<ltp_CS_rap1_pt1->Eval(cpmCentre[0][1])<<" $ & $ "<<ltilde_CS_rap1_pt1->Eval(cpmCentre[0][1])<<" $ \\\\"<<endl;
cout<<"20--30 & $ "<<lth_CS_rap1_pt1->Eval(cpmCentre[0][2])<<" $ & $ "<<lph_CS_rap1_pt1->Eval(cpmCentre[0][2])<<" $ & $ "<<ltp_CS_rap1_pt1->Eval(cpmCentre[0][2])<<" $ & $ "<<ltilde_CS_rap1_pt1->Eval(cpmCentre[0][2])<<" $ \\\\"<<endl;
cout<<"30--60 & $ "<<lth_CS_rap1_pt1->Eval(cpmCentre[0][3])<<" $ & $ "<<lph_CS_rap1_pt1->Eval(cpmCentre[0][3])<<" $ & $ "<<ltp_CS_rap1_pt1->Eval(cpmCentre[0][3])<<" $ & $ "<<ltilde_CS_rap1_pt1->Eval(cpmCentre[0][3])<<" $ \\\\"<<endl;

cout<<endl;

cout<<"HX"<<endl<<endl;
cout<<" 0--10 & $ "<<lth_HX_rap1_pt1->Eval(cpmCentre[0][0])<<" $ & $ "<<lph_HX_rap1_pt1->Eval(cpmCentre[0][0])<<" $ & $ "<<ltp_HX_rap1_pt1->Eval(cpmCentre[0][0])<<" $ & $ "<<ltilde_HX_rap1_pt1->Eval(cpmCentre[0][0])<<" $ \\\\"<<endl;
cout<<"10--20 & $ "<<lth_HX_rap1_pt1->Eval(cpmCentre[0][1])<<" $ & $ "<<lph_HX_rap1_pt1->Eval(cpmCentre[0][1])<<" $ & $ "<<ltp_HX_rap1_pt1->Eval(cpmCentre[0][1])<<" $ & $ "<<ltilde_HX_rap1_pt1->Eval(cpmCentre[0][1])<<" $ \\\\"<<endl;
cout<<"20--30 & $ "<<lth_HX_rap1_pt1->Eval(cpmCentre[0][2])<<" $ & $ "<<lph_HX_rap1_pt1->Eval(cpmCentre[0][2])<<" $ & $ "<<ltp_HX_rap1_pt1->Eval(cpmCentre[0][2])<<" $ & $ "<<ltilde_HX_rap1_pt1->Eval(cpmCentre[0][2])<<" $ \\\\"<<endl;
cout<<"30--60 & $ "<<lth_HX_rap1_pt1->Eval(cpmCentre[0][3])<<" $ & $ "<<lph_HX_rap1_pt1->Eval(cpmCentre[0][3])<<" $ & $ "<<ltp_HX_rap1_pt1->Eval(cpmCentre[0][3])<<" $ & $ "<<ltilde_HX_rap1_pt1->Eval(cpmCentre[0][3])<<" $ \\\\"<<endl;

cout<<endl; 

cout<<"PX"<<endl<<endl;
cout<<" 0--10 & $ "<<lth_PX_rap1_pt1->Eval(cpmCentre[0][0])<<" $ & $ "<<lph_PX_rap1_pt1->Eval(cpmCentre[0][0])<<" $ & $ "<<ltp_PX_rap1_pt1->Eval(cpmCentre[0][0])<<" $ & $ "<<ltilde_PX_rap1_pt1->Eval(cpmCentre[0][0])<<" $ \\\\"<<endl;
cout<<"10--20 & $ "<<lth_PX_rap1_pt1->Eval(cpmCentre[0][1])<<" $ & $ "<<lph_PX_rap1_pt1->Eval(cpmCentre[0][1])<<" $ & $ "<<ltp_PX_rap1_pt1->Eval(cpmCentre[0][1])<<" $ & $ "<<ltilde_PX_rap1_pt1->Eval(cpmCentre[0][1])<<" $ \\\\"<<endl;
cout<<"20--30 & $ "<<lth_PX_rap1_pt1->Eval(cpmCentre[0][2])<<" $ & $ "<<lph_PX_rap1_pt1->Eval(cpmCentre[0][2])<<" $ & $ "<<ltp_PX_rap1_pt1->Eval(cpmCentre[0][2])<<" $ & $ "<<ltilde_PX_rap1_pt1->Eval(cpmCentre[0][2])<<" $ \\\\"<<endl;
cout<<"30--60 & $ "<<lth_PX_rap1_pt1->Eval(cpmCentre[0][3])<<" $ & $ "<<lph_PX_rap1_pt1->Eval(cpmCentre[0][3])<<" $ & $ "<<ltp_PX_rap1_pt1->Eval(cpmCentre[0][3])<<" $ & $ "<<ltilde_PX_rap1_pt1->Eval(cpmCentre[0][3])<<" $ \\\\"<<endl;

cout<<endl; 

}

