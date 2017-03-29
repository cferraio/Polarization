{



//double cpmCentre[2][5]={{6.61274, 14.9849, 24.5775, 34.4264, 46.9469},{6.95899, 15.2337, 24.6783, 34.4796, 46.9283}};
//double cpmCentre[2][5]={{6.56058, 14.9981, 24.5752, 34.4017, 46.8499},{6.97436, 15.2225, 24.7254, 34.531, 46.9052}};
//double cpmCentre[2][5]={{6.52768, 14.9376, 24.533, 34.3689, 46.9187},{6.90424, 15.1098, 24.6705, 34.4013, 46.982}};
double cpmCentre[2][4]={{6.52768, 14.9376, 24.533, 39.1316},{6.90424, 15.1098, 24.6705, 39.3129}};

  	cout<<"For CS, pt 1 "<<endl;
  for(int cpm = 0; cpm < 5; cpm++)
  {
  	if(cpm==0) cout<<"0--10 & ";
  	if(cpm==1) cout<<"10--20 & ";
  	if(cpm==2) cout<<"20--30 & ";
  	if(cpm==3) cout<<"30--40 & ";
  	if(cpm==4) cout<<"40--60 & ";
    cout<<"$"<<lth_CS_rap1_pt1->Eval(cpmCentre[0][cpm])<<"$ & $"<<lph_CS_rap1_pt1->Eval(cpmCentre[0][cpm])<<"$ & $"<<ltp_CS_rap1_pt1->Eval(cpmCentre[0][cpm])<<"$ & $$ \\\\"<<endl;
  }
cout<<"For HX, pt 1 "<<endl;
  for(int cpm = 0; cpm < 5; cpm++)
  {

  	if(cpm==0) cout<<"0--10 & ";
  	if(cpm==1) cout<<"10--20 & ";
  	if(cpm==2) cout<<"20--30 & ";
  	if(cpm==3) cout<<"30--40 & ";
  	if(cpm==4) cout<<"40--60 & ";
    cout<<"$"<<lth_HX_rap1_pt1->Eval(cpmCentre[0][cpm])<<"$ & $"<<lph_HX_rap1_pt1->Eval(cpmCentre[0][cpm])<<"$ & $"<<ltp_HX_rap1_pt1->Eval(cpmCentre[0][cpm])<<"$ & $$ \\\\"<<endl;
    

	}
cout<<"For PX, pt 1 "<<endl;
  for(int cpm = 0; cpm < 5; cpm++)
  {
	  	if(cpm==0) cout<<"0--10 & ";
  	if(cpm==1) cout<<"10--20 & ";
  	if(cpm==2) cout<<"20--30 & ";
  	if(cpm==3) cout<<"30--40 & ";
  	if(cpm==4) cout<<"40--60 & ";
    cout<<"$"<<lth_PX_rap1_pt1->Eval(cpmCentre[0][cpm])<<"$ & $ "<<lph_PX_rap1_pt1->Eval(cpmCentre[0][cpm])<<"$ & $"<<ltp_PX_rap1_pt1->Eval(cpmCentre[0][cpm])<<"$ & $$ \\\\"<<endl;
	}


	cout<<"For CS, pt 2 "<<endl;
	  for(int cpm = 0; cpm < 5; cpm++)
  {

    if(cpm==0) cout<<"0--10 & ";
  	if(cpm==1) cout<<"10--20 & ";
  	if(cpm==2) cout<<"20--30 & ";
  	if(cpm==3) cout<<"30--40 & ";
  	if(cpm==4) cout<<"40--60 & ";
    cout<<"$"<<lth_CS_rap1_pt2->Eval(cpmCentre[1][cpm])<<"$ & $"<<lph_CS_rap1_pt2->Eval(cpmCentre[1][cpm])<<"$ & $"<<ltp_CS_rap1_pt2->Eval(cpmCentre[1][cpm])<<"$ & $$ \\\\"<<endl;
    }
cout<<"For HX, pt 2 "<<endl;
      for(int cpm = 0; cpm < 5; cpm++)
  {

    if(cpm==0) cout<<"0--10 & ";
  	if(cpm==1) cout<<"10--20 & ";
  	if(cpm==2) cout<<"20--30 & ";
  	if(cpm==3) cout<<"30--40 & ";
  	if(cpm==4) cout<<"40--60 & ";
    cout<<"$"<<lth_HX_rap1_pt2->Eval(cpmCentre[1][cpm])<<"$ & $"<<lph_HX_rap1_pt2->Eval(cpmCentre[1][cpm])<<"$ & $"<<ltp_HX_rap1_pt2->Eval(cpmCentre[1][cpm])<<"$ & $$ \\\\"<<endl;
    }
   cout<<"For PX, pt 2 "<<endl;
   for(int cpm = 0; cpm < 5; cpm++)
  {
    if(cpm==0) cout<<"0--10 & ";
  	if(cpm==1) cout<<"10--20 & ";
  	if(cpm==2) cout<<"20--30 & ";
  	if(cpm==3) cout<<"30--40 & ";
  	if(cpm==4) cout<<"40--60 & ";
    cout<<"$"<<lth_PX_rap1_pt2->Eval(cpmCentre[1][cpm])<<"$ & $"<<lph_PX_rap1_pt2->Eval(cpmCentre[1][cpm])<<"$ & $"<<ltp_PX_rap1_pt2->Eval(cpmCentre[1][cpm])<<"$ & $$ \\\\"<<endl;
    }
	
	}