{

bool psi1s = false;

if(!psi1s) {
TFile *f1 = TFile::Open("/data/users/ferraioc/Polarization/JPsi/NchBins/Data/ThirdResults_ForPreApproval_fracL-1_Smeared/TGraphResults_Psi2S.root");

TFile *f2 = TFile::Open("/data/users/ferraioc/Polarization/Final_TGraphs/TGraphResults_Psi2S_1sigma_NchInt.root");

double ptarray[2][5] = {{16.1559, 16.2708, 16.3187, 16.3918, 16.3673},{23.8484, 24.0873, 24.4134, 24.6744, 24.7481}};

int cpmbins = 5;
int ptbins = 2;
int rapbins = 3;
TGraphErrors *newTGraph[4][3][2];
}


if(psi1s) {
TFile *f1 = TFile::Open("/data/users/ferraioc/Polarization/JPsi/NchBins/Data/ThirdResults_ForPreApproval_fracL-1_Smeared/TGraphResults_Psi1S.root");

TFile *f2 = TFile::Open("/data/users/ferraioc/Polarization/Final_TGraphs/TGraphResults_Psi1S_1sigma_NchInt.root");

double ptarray[2][12] = {{16.0532, 16.1647, 16.2238, 16.2575, 16.2764, 16.293, 16.313, 16.3256, 16.3622, 16.3753, 16.3668, 16.3989},{23.5564, 23.8465, 24.0204, 24.1733, 24.246, 24.3788, 24.3794, 24.5297, 24.5712, 24.6809, 24.7514, 24.9711}};

int cpmbins = 12;
int ptbins = 2;
int rapbins = 2;
TGraphErrors *newTGraph[4][3][3];
}


TGraphAsymmErrors *oldTGraph[4][3];



char graphname[100];
char whichlam[100];
char whichframe[100];
double cpmYval[cpmbins];
double cpmYvalErr[cpmbins];
double x;

leg = new TLegend(0.7,0.75,0.9,0.9);


f1.cd();
for(int lambda = 0; lambda < 4; lambda++)
{
	if (lambda == 0) sprintf(whichlam,"th");
	if (lambda == 1) sprintf(whichlam,"ph");
	if (lambda == 2) sprintf(whichlam,"tp");
	if (lambda == 3) sprintf(whichlam,"tilde");
	
	for(int frame = 0; frame < 3; frame++)
	{
	  if (frame == 0) sprintf(whichframe,"CS");
	  if (frame == 1) sprintf(whichframe,"PX");
	  if (frame == 2) sprintf(whichframe,"HX");
	
		for(int pt = 0; pt < ptbins; pt++)
		{
			sprintf(graphname,"l%s_%s_rap1_pt%d",whichlam,whichframe,pt+1);
			oldTGraph[lambda][frame] = (TGraphAsymmErrors*)f1->Get(graphname);
			
			for(int cpm = 0; cpm < cpmbins; cpm++)
			{
				oldTGraph[lambda][frame]->GetPoint(cpm,x,cpmYval[cpm]);
				cpmYvalErr[cpm] = oldTGraph[lambda][frame]->GetErrorY(cpm);
			}
			newTGraph[lambda][frame][pt] = new TGraphErrors(cpmbins,ptarray[pt],cpmYval,0,cpmYvalErr);
		}
	}
}
//FinalResults/NchBinComp

f2.cd();

TCanvas *c1 = new TCanvas("Comparison of NchInt to Binned","Comparison of NchInt to Binned",600,400); 
char savename[200];

for(int lambda = 0; lambda < 4; lambda++)
{
	if (lambda == 0) sprintf(whichlam,"th");
	if (lambda == 1) sprintf(whichlam,"ph");
	if (lambda == 2) sprintf(whichlam,"tp");
	if (lambda == 3) sprintf(whichlam,"tilde");
	
	for(int frame = 0; frame < 3; frame++)
	{
	  if (frame == 0) sprintf(whichframe,"CS");
	  if (frame == 1) sprintf(whichframe,"PX");
	  if (frame == 2) sprintf(whichframe,"HX");

		for(int rap = 0; rap < rapbins; rap++)
		{

			sprintf(graphname,"l%s_%s_rap%d",whichlam,whichframe,rap+1);
			oldTGraph[lambda][frame] = (TGraphAsymmErrors*)f2->Get(graphname);
			oldTGraph[lambda][frame]->SetMarkerStyle(21);
			
			oldTGraph[lambda][frame]->SetMarkerColor(2);
			oldTGraph[lambda][frame]->SetMarkerSize(1);
			
			if (lambda == 1 || lambda == 2) oldTGraph[lambda][frame]->GetYaxis()->SetRangeUser(-.35,.35);
			else oldTGraph[lambda][frame]->GetYaxis()->SetRangeUser(-1,1);
			
			oldTGraph[lambda][frame]->SetTitle("");
			oldTGraph[lambda][frame]->GetXaxis()->SetTitleOffset(1.1);
			oldTGraph[lambda][frame]->GetYaxis()->SetTitleOffset(.8);
			oldTGraph[lambda][frame]->GetXaxis()->SetTitle("p_{T}");
			if(lambda == 0) oldTGraph[lambda][frame]->GetYaxis()->SetTitle("#lambda_{#theta}");
			if(lambda == 1) oldTGraph[lambda][frame]->GetYaxis()->SetTitle("#lambda_{#phi}");
			if(lambda == 2) oldTGraph[lambda][frame]->GetYaxis()->SetTitle("#lambda_{#theta#phi}");
			if(lambda == 3) oldTGraph[lambda][frame]->GetYaxis()->SetTitle("#lambda_{tilde}");
			if (rap == 0) oldTGraph[lambda][frame]->Draw("ap");
			else oldTGraph[lambda][frame]->Draw("psame");
			
			for(int pt = 0; pt < ptbins; pt++)
			{

				newTGraph[lambda][frame][pt]->SetMarkerStyle(20);
				newTGraph[lambda][frame][pt]->SetMarkerColor(1);
				newTGraph[lambda][frame][pt]->Draw("psame");
			}
			
		} 
	//	if(lambda == 0) hFrame->SetXTitle("#lambda_{#theta}");
///		if(lambda == 1) hFrame->SetXTitle("#lambda_{#theta}");
//		if(lambda == 2) hFrame->SetXTitle("#lambda_{#theta}");
//		if(lambda == 3) hFrame->SetXTitle("#lambda_{#theta}");
		if(lambda == 0 && frame == 0) leg->AddEntry(newTGraph[0][0][0],"N_{ch} Bins","p");
		if(lambda == 0 && frame == 0) leg->AddEntry(oldTGraph[0][0],"N_{ch} Int","p");
		leg->Draw();
		if(psi1s) sprintf(savename,"FinalResults/NchBinComp/Psi1S_l%s_%s_comp.pdf",whichlam,whichframe);
		if(!psi1s) sprintf(savename,"FinalResults/NchBinComp/Psi2S_l%s_%s_comp.pdf",whichlam,whichframe);
		c1->SaveAs(savename);
	}
}

}
