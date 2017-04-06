namespace ToyMC{

double ScenarioSig [3][9]={{-1,-0.5,0,0.5,1,0,0,0.5,1},{0,0,0,0,0,0.5,-0.5,-0.75,-1},{0,0,0,0,0,0,0,0,0}};//lamth_Signal,lamph_Signal,lamthph_Signal

double ScenarioBkg [3][9]={{-1,-0.5,0,-0.25,1,0,0,2,4},{0,0,0,0.15,0,0.5,0.8,0.4,-0.4},{0,0,0,0,0,0,0,0,0}};////lamth_Bkg,lamph_Bkg,lamthph_Bkg


int MarkerStyle[6][4]={{0,0,0,0},{0,33,27,34},{0,20,24,29},{0,21,25,22},
	{0,33,27,34},{0,20,24,29}}; // for each state, rapBin (1= closed, 2=open)
int MarkerColor[6] = {0,1,1,1,1,1};//{0,600,632,418}; // for each frame
double MarkerSize[6][4]={{0,0,0},{0,2.75,2.75,2.75},{0,1.65,1.65,1.65},{0,1.65,1.65,1.65},
	{0,2.75,2.75,2.75},{0,1.65,1.65,1.65}};// for each state, rapBin

const int ncpmBins=5;
const int nPtBins=2;
const int nRapBins=1;

double ptCentre[nRapBins][nPtBins][ncpmBins]={{{16.1559, 16.2708, 16.3187, 16.3918, 16.3673},{23.8484, 24.0873, 24.4134, 24.6744, 24.7481}}};

double cpmCentre[nRapBins][nPtBins][ncpmBins]={{{10.2461, 19.9083, 29.5757, 39.3869, 53.9924},{10.7184, 20.0851, 29.6918, 39.5096, 54.7772}}};

double meanRap[nRapBins][nPtBins][ncpmBins]={{{0.717556, 0.720808, 0.695792, 0.701389, 0.696037},{0.702049, 0.701976, 0.711596, 0.709246, 0.690889}}};

double fracBackground[nRapBins][nPtBins][ncpmBins]={{{0.001,0.001,0.001,0.001,0.001},{0.001,0.001,0.001,0.001,0.001}}};

int numEvents[nRapBins][nPtBins][ncpmBins]={{{10989, 15332, 10907, 5982, 3758},{2413, 4725, 3956, 2365, 1805}}};



//CS 
//int binCosth[nRapBins][nPtBins][ncpmBins]={{{32, 64, 64, 32, 32},{16, 32, 32, 16, 16}}};

//CS 
//int binPhi[nRapBins][nPtBins][ncpmBins]={{{16, 16, 16, 16, 16},{16, 16, 16, 16, 16}}};

//HX int binCosth[nRapBins][nPtBins][ncpmBins]={{32, 64, 64, 32, 32},{16, 32, 32, 16, 16}};

//HX int binPhi[nRapBins][nPtBins][ncpmBins]={{16, 16, 16, 16, 16},{16, 16, 16, 16, 16}};

//PHX 
int binPhi[nRapBins][nPtBins][ncpmBins]={{{16, 16, 16, 16, 16},{16, 16, 16, 16, 16}}};

//PHX 
int binCosth[nRapBins][nPtBins][ncpmBins]={{{32, 64, 64, 32, 32},{16, 32, 32, 16, 16}}};

const int nEffs=3;
const int FidCuts=3;

}
