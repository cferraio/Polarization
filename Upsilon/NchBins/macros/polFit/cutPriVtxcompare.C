#include<iomanip>

int cutPriVtxcompare()
{


std::cout << std::fixed;
std::cout << std::setprecision(3);

for(int state = 0; state < 1; state++)
{
  int Ups;
  if( state == 0) Ups = 1;
  if( state == 1) Ups = 3;


char file1name[200];
sprintf(file1name,"/data/users/ferraioc/Polarization/Modified/Data/GreatCPMRun2/TGraphResults_%dSUps.root",Ups);
TFile* file1 = new TFile(file1name);

char file2name[200];
sprintf(file2name,"/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx/TGraphResults_%dSUps.root",Ups);
TFile* file2 = new TFile(file2name);

char file3name[200];
sprintf(file3name,"/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx_at10/TGraphResults_%dSUps.root",Ups);
TFile* file3 = new TFile(file3name);

for(int lam = 0; lam < 4; lam ++)
{
 char lambda[200];
 if(lam == 0) sprintf(lambda,"lth");
 if(lam == 1) sprintf(lambda,"lph");
 if(lam == 2) sprintf(lambda,"ltp");
 if(lam == 3) sprintf(lambda,"ltilde");
 

 
/*for(int frame = 0; frame < 3; frame++)
{
 char whichframe[200];
 if(frame == 0) sprintf(whichframe,"CS");
 if(frame == 1) sprintf(whichframe,"HX");
 if(frame == 2) sprintf(whichframe,"PX");
 
 cout<<"For frame "<<whichframe<<endl;
 */
 		char graphname[200];
        sprintf(graphname,"%s_PX_rap1_pt2", lambda); 
 		theTGraph = (TGraphAsymmErrors*) file1->Get(graphname);

        int cpmMax = 5;
        if(state==1) int cpmMax = 4;
        Double_t  cpmCenter1;
		Double_t  lmeanth1;
		Double_t  lmeanph1;
		Double_t  lmeantp1;
		Double_t  lmeantilde1;
		Double_t  elmeanth1;
		Double_t  elmeanph1;
		Double_t  elmeantp1;
		Double_t  elmeantilde1;
		Double_t  cpmCenter2;
		Double_t  lmeanth2;
		Double_t  lmeanph2;
		Double_t  lmeantp2;
		Double_t  lmeantilde2;
		Double_t  elmeanth2;
		Double_t  elmeanph2;
		Double_t  elmeantp2;
		Double_t  elmeantilde2;
		Double_t  cpmCenter3;
		Double_t  lmeanth3;
		Double_t  lmeanph3;
		Double_t  lmeantp3;
		Double_t  lmeantilde3;
		Double_t  elmeanth3;
		Double_t  elmeanph3;
		Double_t  elmeantp3;
		Double_t  elmeantilde3;
        
          if(lam==0) theTGraph->GetPoint(0,cpmCenter1,lmeanth1);
          if(lam==1) theTGraph->GetPoint(0,cpmCenter1,lmeanph1);
          if(lam==2) theTGraph->GetPoint(0,cpmCenter1,lmeantp1);
          if(lam==3) theTGraph->GetPoint(0,cpmCenter1,lmeantilde1);
		  if(lam==0) elmeanth1=theTGraph->GetErrorY(0);
		  if(lam==1) elmeanph1=theTGraph->GetErrorY(0);
		  if(lam==2) elmeantp1=theTGraph->GetErrorY(0);
		  if(lam==3) elmeantilde1=theTGraph->GetErrorY(0);
         
 
	    
        theTGraph = (TGraphAsymmErrors*) file2->Get(graphname);
        int cpmMax = 5;
        if(state==1) int cpmMax = 4;
        
          if(lam==0) theTGraph->GetPoint(0,cpmCenter2,lmeanth2);
          if(lam==1) theTGraph->GetPoint(0,cpmCenter2,lmeanph2);
          if(lam==2) theTGraph->GetPoint(0,cpmCenter2,lmeantp2);
          if(lam==3) theTGraph->GetPoint(0,cpmCenter2,lmeantilde2);
		  if(lam==0) elmeanth2=theTGraph->GetErrorY(0);
		  if(lam==1) elmeanph2=theTGraph->GetErrorY(0);
		  if(lam==2) elmeantp2=theTGraph->GetErrorY(0);
		  if(lam==3) elmeantilde2=theTGraph->GetErrorY(0);
         
		  
		theTGraph = (TGraphAsymmErrors*) file3->Get(graphname);
          if(lam==0) theTGraph->GetPoint(0,cpmCenter3,lmeanth3);
          if(lam==1) theTGraph->GetPoint(0,cpmCenter3,lmeanph3);
          if(lam==2) theTGraph->GetPoint(0,cpmCenter3,lmeantp3);
          if(lam==3) theTGraph->GetPoint(0,cpmCenter3,lmeantilde3);
		  if(lam==0) elmeanth3=theTGraph->GetErrorY(0);
		  if(lam==1) elmeanph3=theTGraph->GetErrorY(0);
		  if(lam==2) elmeantp3=theTGraph->GetErrorY(0);
		  if(lam==3) elmeantilde3=theTGraph->GetErrorY(0);
         
         
}


		
		
		

		  
//		  cout<< "No cut  & " <<lmeanth1<<"pm "<<elmeanth1<<" & "<<lmeanph1<<"+- "<<elmeanph1<<" & "<<lmeantp1<<"+-"<<elmeantp1<<" & "<<lmeantilde1<<"+-"<<elmeantilde1<<" \\\\"<<endl;
		  
		  cout<< "Cutat16 & "<<lmeanth2<<"pm "<<elmeanth2<<" & "<<lmeanph2<<"+- "<<elmeanph2<<" & "<<lmeantp2<<"+-"<<elmeantp2<<" & "<<lmeantilde2<<"+-"<<elmeantilde2<<" \\\\"<<endl;
		 
		  cout<< "Cutat10 & "<<lmeanth3<<"pm "<<elmeanth3<<" & "<<lmeanph3<<"+- "<<elmeanph3<<" & "<<lmeantp3<<"+-"<<elmeantp3<<" & "<<lmeantilde3<<"+-"<<elmeantilde3<<" \\\\"<<endl;
		  
		  cout<<endl;
		  
	//	  }
		  
		  
 



}}