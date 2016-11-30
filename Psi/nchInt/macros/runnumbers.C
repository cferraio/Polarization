{

TFile *_file0 = TFile::Open("DataFiles/SetOfCuts11_ctauScen0_FracLSB-1_2012Run3/Psi1S/tmpFiles/data_Psi1S_rap1_pT1.root");


double runnb;
selectedData->SetBranchAddress("runNb", &runnb);

int entries = selectedData->GetEntries();

std::vector<int> runnumbers;
int runNum;
int sz; 

for(int i = 0; i < entries; i++)
{

selectedData->GetEntry(i);

if(i == 0) runnumbers.push_back (runnb);

sz = runnumbers.size();
int val=0;
for(int x = 0; x < sz; x++)
{
	if(runnb == runnumbers[val]) break;
	else if(runnb != runnumbers[val]) val++; 
	if(runnb != runnumbers[val] && val ==sz) runnumbers.push_back (runnb); 
}


}

sz = runnumbers.size();
for(int x = 0; x < sz; x++){
	cout<<runnumbers[x]<<endl;
}

}