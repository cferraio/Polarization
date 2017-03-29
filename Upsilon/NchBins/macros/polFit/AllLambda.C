{
Char_t *storagedir = "/data/users/ferraioc/Polarization/Modified/Data";
Char_t *DefaultID = "cutNPriVtx_smallerpT2_FinalSyst";
Int_t const NXBINS = 5;
Double_t cpmRange[NXBINS+1] = {0, 10, 20, 30, 40, 60};
int cpmBinMin=1;
int cpmBinMax=5;
double DeltaXminOVERALL=0.;
char GraphName[200], axislabel[200];
char beginLamLabel[200];
sprintf(beginLamLabel,"");
char endLamLabel[200];
sprintf(endLamLabel,"");
int rapBin = 1;

for(int iStateMP = 1; iStateMP < 4; iStateMP++){

char filename[200];
sprintf(filename,"%s/%s/TGraphResults_%dSUps.root",storagedir,DefaultID,iStateMP);
TFile *infileRes = new TFile(filename,"READ");
		
for(int iLam = 1; iLam<12+1; iLam++){
for(int ptBin = 1; ptBin < 3; ptBin++)
{
if(iLam==1)  sprintf(GraphName,"lth_CS_rap%d_pt%d",rapBin,ptBin);
if(iLam==2)  sprintf(GraphName,"lph_CS_rap%d_pt%d",rapBin,ptBin);
if(iLam==3)  sprintf(GraphName,"ltp_CS_rap%d_pt%d",rapBin,ptBin);
if(iLam==4)  sprintf(GraphName,"ltilde_CS_rap%d_pt%d",rapBin,ptBin);
if(iLam==5)  sprintf(GraphName,"lth_HX_rap%d_pt%d",rapBin,ptBin);
if(iLam==6)  sprintf(GraphName,"lph_HX_rap%d_pt%d",rapBin,ptBin);
if(iLam==7)  sprintf(GraphName,"ltp_HX_rap%d_pt%d",rapBin,ptBin);
if(iLam==8) sprintf(GraphName,"ltilde_HX_rap%d_pt%d",rapBin,ptBin);
if(iLam==9) sprintf(GraphName,"lth_PX_rap%d_pt%d",rapBin,ptBin);
if(iLam==10) sprintf(GraphName,"lph_PX_rap%d_pt%d",rapBin,ptBin);
if(iLam==11) sprintf(GraphName,"ltp_PX_rap%d_pt%d",rapBin,ptBin);
if(iLam==12) sprintf(GraphName,"ltilde_PX_rap%d_pt%d",rapBin,ptBin);
		
double yMin,yMax;
yMin=-1.1;
yMax=1.1;
int MPframe;
int iPanel;
float Top_margin   = 0.;//0
float Left_margin  = 0.15;//0.025
float Right_margin = 0.015;//0.005
const int nPanels=4;
double lowestBottomMargin=0.2;//0.2
double PadCoordYMax=0.985;//0.985
double deltaCoordY=PadCoordYMax/(double(nPanels-1)+1./(1-lowestBottomMargin));
double startValCoordY=deltaCoordY/(1-lowestBottomMargin);
double PadCoordY[nPanels+1]={0.,startValCoordY,startValCoordY+deltaCoordY,PadCoordYMax};
double PadCoordX[3]={0.1,0.5,0.9};

int MPcanvasXpixelInitial=3000;
int MPcanvasYpixelInitial=3000;
int MPcanvasXpixel=MPcanvasXpixelInitial;
int MPcanvasYpixel=MPcanvasYpixelInitial;
double yMinMP=yMin+0.01;
double yMaxMP=yMax-0.01;
double LabelSize=0.065;
double TitleSize=0.085;
double titleoffset=-0.65;
double ticksize=0.015;
int AxisDivisions=510;
double deltaTrickAxisMin=-0.001;
double deltaTrickAxisMax=-0.001;
if(ptBin==2) deltaTrickAxisMax=+0.001;

double whereTexteInPlotX;
double whereTexteInPlotY;
double labelOffsetX=0.02;
double YaxistitleLatexSize=0.12;
double MPlatexX=11.5;
double MPlatexYmax=(yMax-yMin)*0.8775+yMin;
double MPlatexDeltaYmax=0.09*(yMax-yMin);
double CentralsFontSizeMP=0.115;
double textSizeRap=0.07825;
double xRapText;
double xRapTextTilde;
double yRapText=0.06;
if(ptBin==1) xRapText=cpmRange[cpmBinMax]*0.825;
if(ptBin==2) xRapText=cpmRange[cpmBinMax]*0.725;
if(ptBin==1) xRapTextTilde=cpmRange[cpmBinMax]*0.7;
if(ptBin==2) xRapTextTilde=cpmRange[cpmBinMax]*0.6;
double xabcdefText=cpmRange[cpmBinMax]*0.225;
double XaxislabelLatexSize=0.0245;
double YtitleAngle=0.;
double XtitlePosition=-8.;
double XtitlePositionYshift=0.025;
double MarkerSizeMP[4]={3.75,3.75,3.75,4.15};
int MarkerColorMP[4] = {1,1,632,600};
int MarkerStyleMP[5] = {25,20,25,24,27};
int MarkerStyleMPtilde[4] = {20,24,25,27};
double errorLegendX1=0.165;
double errorLegendX2=0.565;
double errorLegendY1=0.655;
double errorLegendY2=0.95;
double errorLegendFontSize=0.08;

cout<<"begin Frame dependent plots"<<endl;

if(iLam==1)  sprintf(axislabel,"#lambda^{CS}_{#vartheta}%s",beginLamLabel,endLamLabel);
if(iLam==2)  sprintf(axislabel,"#lambda^{CS}_{#varphi}%s",beginLamLabel,endLamLabel);
if(iLam==3)  sprintf(axislabel,"#lambda^{CS}_{#vartheta#varphi}%s",beginLamLabel,endLamLabel);
if(iLam==4)  sprintf(axislabel,"#tilde{#lambda}^{CS}%s",beginLamLabel,endLamLabel);
if(iLam==5)  sprintf(axislabel,"#lambda^{HX}_{#vartheta}%s",beginLamLabel,endLamLabel);
if(iLam==6)  sprintf(axislabel,"#lambda^{HX}_{#varphi}%s",beginLamLabel,endLamLabel);
if(iLam==7)  sprintf(axislabel,"#lambda^{HX}_{#vartheta#varphi}%s",beginLamLabel,endLamLabel);
if(iLam==8) sprintf(axislabel,"#tilde{#lambda}^{HX}%s",beginLamLabel,endLamLabel);
if(iLam==9) sprintf(axislabel,"#lambda^{PX}_{#vartheta}%s",beginLamLabel,endLamLabel);
if(iLam==10) sprintf(axislabel,"#lambda^{PX}_{#varphi}%s",beginLamLabel,endLamLabel);
if(iLam==11) sprintf(axislabel,"#lambda^{PX}_{#vartheta#varphi}%s",beginLamLabel,endLamLabel);
if(iLam==12) sprintf(axislabel,"#tilde{#lambda}^{PX}%s",beginLamLabel,endLamLabel);//IfLamTildeClosure no PX

if(iLam>0&&iLam<5) MPframe=1;
if(iLam>4&&iLam<8) MPframe=2;
if(iLam>8&&iLam<13) MPframe=3;
if(iLam==1||iLam==5||iLam==9)  iPanel=1;
if(iLam==2||iLam==6||iLam==10) iPanel=2;
if(iLam==3||iLam==7||iLam==11) iPanel=3;
if(iLam==4||iLam==8||iLam==12) iPanel=4;

if(iLam==1&&ptBin==1){
MPcanvasCS = new TCanvas("MPcanvasCS", "MPcanvasCS",MPcanvasXpixel,MPcanvasYpixel);
MPcanvasCS->SetFillColor(kWhite);
MPcanvasCS->GetFrame()->SetFillColor(kWhite);
MPcanvasCS->GetFrame()->SetBorderSize(0);
} //end if
if(iLam==5&&ptBin==1){
MPcanvasHX = new TCanvas("MPcanvasHX", "MPcanvasHX",MPcanvasXpixel,MPcanvasYpixel);
MPcanvasHX->SetFillColor(kWhite);
MPcanvasHX->GetFrame()->SetFillColor(kWhite);
MPcanvasHX->GetFrame()->SetBorderSize(0);
} //end if
if(iLam==9&&ptBin==1){
MPcanvasPX = new TCanvas("MPcanvasPX", "MPcanvasPX",MPcanvasXpixel,MPcanvasYpixel);
MPcanvasPX->SetFillColor(kWhite);
MPcanvasPX->GetFrame()->SetFillColor(kWhite);
MPcanvasPX->GetFrame()->SetBorderSize(0);
} //end if

for(int iStateMP=1;iStateMP<4;iStateMP++){
if(MPframe==1) MPcanvasCS->cd();
if(MPframe==2) MPcanvasHX->cd();
if(MPframe==3) MPcanvasPX->cd();


}
TGraphAsymmErrors* graphDefaultRes = (TGraphAsymmErrors*) infileRes->Get(GraphName);
infileRes->Get(GraphName);

cout<<"MultiPanel pad"<<endl;
TPad *MPpad;
TPad("MPpad","MPpad",PadCoordX_newMP[iStateMP-1],PadCoordY_MPnew[nPanels_MPnew-iPanel],PadCoordX_newMP[iStateMP],PadCoordY_MPnew[nPanels_MPnew-iPanel+1]);
MPpad->Draw();
MPpad->cd();
MPpad->SetFillColor(kWhite);
MPpad->SetFrameFillColor(kWhite);
MPpad->SetBorderSize(0);
MPpad->SetLeftMargin(0.);
if(iStateMP==1) MPpad->SetLeftMargin(Left_margin);
MPpad->SetRightMargin(0.);
if(iStateMP==3) MPpad->SetRightMargin(Right_margin);
MPpad->SetTopMargin(Top_margin+0.0025);
MPpad->SetBottomMargin(0.0);
if(iPanel==nPanels) MPpad->SetBottomMargin(lowestBottomMargin);

double deltaXaxisMin=0.;

cout<<"MultiPanel hist"<<endl;
TH1F *MPhist = new TH1F;
if(MPframe==1)MPhist = MPcanvasCS_rap1_pt1->DrawFrame(cpmRange[cpmBinMin-1]-DeltaXminOVERALL-deltaXaxisMin,yMinMP,cpmRange[cpmBinMax],yMaxMP);
if(MPframe==2)MPhist = MPcanvasHX_rap1_pt1->DrawFrame(cpmRange[cpmBinMin-1]-DeltaXminOVERALL-deltaXaxisMin,yMinMP,cpmRange[cpmBinMax],yMaxMP);
if(MPframe==3)MPhist = MPcanvasPX_rap1_pt1->DrawFrame(cpmRange[cpmBinMin-1]-DeltaXminOVERALL-deltaXaxisMin,yMinMP,cpmRange[cpmBinMax],yMaxMP);






} //end pt bin

} //end iLam

} //end iStateMP




}