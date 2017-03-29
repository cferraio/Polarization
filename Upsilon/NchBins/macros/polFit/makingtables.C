//#include<iomanip>


//int makingtables()
{

//std::cout << std::fixed;
//std::cout << std::setprecision(3);

for(int state = 0; state < 3; state++)
{

	if(state == 0) TFile* filein = new TFile("/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx_smallerpT2_FinalSyst_Glob/TGraphResults_1SUps.root");
	if(state == 1) TFile* filein = new TFile("/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx_smallerpT2_FinalSyst_Glob/TGraphResults_2SUps.root");
	if(state == 2) TFile* filein = new TFile("/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx_smallerpT2_FinalSyst_Glob/TGraphResults_3SUps.root");
	
	for(int pt = 0; pt < 2; pt++)
   {

     
     for(int frame = 0; frame<3; frame++)
    {
     char whichframe[200];
     if(frame==0) sprintf(whichframe,"HX");
     if(frame==1) sprintf(whichframe,"CS");
     if(frame==2) sprintf(whichframe,"PX");
      
     for(int lambda = 0; lambda < 4; lambda++)
     {
      char whichlambda[200];
      if(lambda == 0) sprintf(whichlambda,"th");
      if(lambda == 1) sprintf(whichlambda,"ph");
      if(lambda == 2) sprintf(whichlambda,"tp");
      if(lambda == 3) sprintf(whichlambda,"tilde");
      
      char graphname[200];
      sprintf(graphname,"l%s_%s_rap1_pt%d", whichlambda, whichframe, pt+1); 
      theTGraph = (TGraphAsymmErrors*) filein->Get(graphname);

      
        int cpmMax = 5;
        if(pt==0&&state==2) int cpmMax = 4;
        Double_t cpmCenter[cpmMax];
        Double_t lmean[3][3][4][2][cpmMax];
        Double_t elmeanh[3][3][4][2][cpmMax];
        Double_t elmeanl[3][3][4][2][cpmMax];
        for(int cpmBin = 0; cpmBin < cpmMax; cpmBin++)
         {
          theTGraph->GetPoint(cpmBin,cpmCenter[cpmBin],lmean[state][frame][lambda][pt][cpmBin]);
          elmeanh[state][frame][lambda][pt][cpmBin] = theTGraph->GetErrorYhigh(cpmBin);
          elmeanl[state][frame][lambda][pt][cpmBin] = theTGraph->GetErrorYlow(cpmBin);
         } //end cpm
      
      } //end lambda
    } //end frame
     
   } //end pt
} //end state

for(int state = 0; state < 3; state++)
{
  int whichstate = state+1;
  cout<<"For Upsilon"<<whichstate<<"S, ";
  for(int frame = 0; frame < 3; frame++)
  {
    char whichframe[20];
    if(frame==0) sprintf(whichframe,"HX");
     if(frame==1) sprintf(whichframe,"CS");
     if(frame==2) sprintf(whichframe,"PX");
    cout<<"in frame "<<whichframe<<",";
   for(int pt = 0; pt < 2; pt++)
   {
    cout<<" for pT <<"<<pt+1<<endl;
	int cpmMax = 5;
    if(pt==0&&state==2) int cpmMax = 4;
	for(int cpmBin = 0; cpmBin < cpmMax; cpmBin++)
	{
	   if(cpmBin == 0) cout<<"\\rule{0pt}{4mm} $ 0--10$ ";
	   if(cpmBin == 1) cout<<"\\rule{0pt}{4mm} $10--20$ ";
	   if(cpmBin == 2) cout<<"\\rule{0pt}{4mm} $20--30$ ";
	   if(cpmBin == 3) cout<<"\\rule{0pt}{4mm} $30--40$ ";
	   if(cpmBin == 4) cout<<"\\rule{0pt}{4mm} $40--60$ ";
//	   else cout<<"$40--60$";
	   
	   for(int lamda = 0; lamda < 4; lamda++)
	   {
	      cout<<" & $"<<lmean[state][frame][lamda][pt][cpmBin]<<"^{+"<<elmeanh[state][frame][lamda][pt][cpmBin]<<"}_{-"<<elmeanl[state][frame][lamda][pt][cpmBin]<<"} $";
	   } //end lam
	   
	   cout<<" \\\\ \\hline"<<endl;
	} //end cpmbin
	cout<<endl;
	} //end pt
	cout<<endl;
  } //end frame
  cout<<endl;
  
 


} //end state


}// end program
