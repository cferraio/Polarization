{TFile *file0 = TFile::Open("Systematics/cutNPriVtx_smallerpT2_FinalSyst/Nch_FrameworkII/TGraphResults_2SUps.root");

char tgraphname[200];
double lamval[4];
double cpmcenter[4];


for(int frame = 0; frame < 3; frame++)
{
  char framename[10];
  if(frame == 0) sprintf(framename,"CS");
  if(frame == 1) sprintf(framename,"HX");
  if(frame == 2) sprintf(framename,"PX");
  
  for(int lam = 0; lam < 4; lam++)
  {
    char lamname[10];
    if(lam == 0) sprintf(lamname,"th");
    if(lam == 1) sprintf(lamname,"ph");
    if(lam == 2) sprintf(lamname,"tp");
    if(lam == 3) sprintf(lamname,"tilde");
  
  
  sprintf(tgraphname,"l%s_%s_rap1_pt1",lamname,framename);
  theTGraph = (TGraph*) file0->Get(tgraphname);
  
  for(int cpmBin = 0; cpmBin < 3; cpmBin++)
  {
  
  	theTGraph->GetPoint(cpmBin,cpmcenter[cpmBin],lamval[cpmBin]);        
  }
  
    lamval[3] = theTGraph->Eval(39.1154);
    cpmcenter[3] = 39.1154;
    
    TFile fout("Systematics/cutNPriVtx_smallerpT2_FinalSyst/Nch_FrameworkII/TGraphResults_3SUps.root","UPDATE");
    
    systTGraph = new TGraph(4,cpmcenter,lamval);
    
    systTGraph->Write(tgraphname);
    
    fout->Close();
    
  }
  
}}

