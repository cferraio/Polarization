{

#include "ToyMC.h"

double cpmCentre[2][5]={{6.61274, 14.9849, 24.5775, 34.4264, 46.9469},{6.95899, 15.2337, 24.6783, 34.4796, 46.9283}};

for(int pt = 1; pt < 3; pt++)
{
  for(int cpm = 1; cpm < 6; cpm++)
  {
  	cout<<"For CS:"<<endl;
    cout<<"pt "<<pt<<" cpm "<<cpm<<" theta: "<<lth_CS_rap1_pt1->Eval(ToyMC::cpmCentre[pt][cpm])<<endl;
	cout<<"pt "<<pt<<" cpm "<<cpm<<" phi: "<<lph_CS_rap1_pt1->Eval(ToyMC::cpmCentre[pt][cpm])<<endl;
	cout<<"pt "<<pt<<" cpm "<<cpm<<" thetaphi: "<<ltp_CS_rap1_pt1->Eval(ToyMC::cpmCentre[pt][cpm])<<endl;
	cout<<"pt "<<pt<<" cpm "<<cpm<<" tilde: "<<ltilde_CS_rap1_pt1->Eval(ToyMC::cpmCentre[pt][cpm])<<endl;
  	cout<<"For HX:"<<endl;
    cout<<"pt "<<pt<<" cpm "<<cpm<<" theta: "<<lth_HX_rap1_pt1->Eval(ToyMC::cpmCentre[pt][cpm])<<endl;
	cout<<"pt "<<pt<<" cpm "<<cpm<<" phi: "<<lph_HX_rap1_pt1->Eval(ToyMC::cpmCentre[pt][cpm])<<endl;
	cout<<"pt "<<pt<<" cpm "<<cpm<<" thetaphi: "<<ltp_HX_rap1_pt1->Eval(ToyMC::cpmCentre[pt][cpm])<<endl;
	cout<<"pt "<<pt<<" cpm "<<cpm<<" tilde: "<<ltilde_HX_rap1_pt1->Eval(ToyMC::cpmCentre[pt][cpm])<<endl;
  	cout<<"For PX:"<<endl;
    cout<<"pt "<<pt<<" cpm "<<cpm<<" theta: "<<lth_PX_rap1_pt1->Eval(ToyMC::cpmCentre[pt][cpm])<<endl;
	cout<<"pt "<<pt<<" cpm "<<cpm<<" phi: "<<lph_PX_rap1_pt1->Eval(ToyMC::cpmCentre[pt][cpm])<<endl;
	cout<<"pt "<<pt<<" cpm "<<cpm<<" thetaphi: "<<ltp_PX_rap1_pt1->Eval(ToyMC::cpmCentre[pt][cpm])<<endl;
	cout<<"pt "<<pt<<" cpm "<<cpm<<" tilde: "<<ltilde_PX_rap1_pt1->Eval(ToyMC::cpmCentre[pt][cpm])<<endl;
  }
}
}