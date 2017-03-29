namespace ToyMC{

double ScenarioSig [3][9]={{-1,-0.5,0,0.5,1,0,0,0.5,1},{0,0,0,0,0,0.5,-0.5,-0.75,-1},{0,0,0,0,0,0,0,0,0}};//lamth_Signal,lamph_Signal,lamthph_Signal

double ScenarioBkg [3][9]={{-1,-0.5,0,0.5,1,0,0,2,4},{0,0,0,0,0,0.5,0.8,0.4,-0.4},{0,0,0,0,0,0,0,0,0}};////lamth_Bkg,lamph_Bkg,lamthph_Bkg


/*int MarkerStyle[3] = {0, 20, 21};
int MarkerStyle2[3] = {0, 24, 25};
int MarkerStyle3[3] = {0, 26, 32};
int MarkerColor[3] = {0, 601, 632};
int MarkerColor2[3] = {0, 632, 632};
int MarkerColor3[3] = {0, 418, 632};
*/
int MarkerStyle[4][3]={{0,20,24},{0,33,27},{0,20,24},{0,21,25}}; // for each state, rapBin (1= closed, 2=open)
//int MarkerColor[4] = {0,1,2,3};//{0,600,632,418}; // for each frame
int MarkerColor[4] = {1,1,1,1};//{0,600,632,418}; // for each frame
double MarkerSize[4][3]={{0,0,0},{0,2.75,2.75},{0,1.65,1.65},{0,1.65,1.65}};// for each state, rapBin

const int nPtBins=2;
const int nRapBins=1;
const int nCPMBins=5;
//const int nCPMBins=4;


//Upsilon(1):

double ptCentre[nPtBins][nCPMBins]={{12.0229, 12.1347, 12.1735, 12.1853, 12.2035},{18.8079, 19.4578, 19.9006, 20.1722, 20.4968}};

double cpmCentre[nPtBins][nCPMBins]={{6.60775, 14.9818, 24.5745, 34.4255, 46.9465},{6.95018, 15.2209, 24.6604, 34.4774, 46.8955}};

int numEvents[nPtBins][nCPMBins]={{26884, 51256, 39233, 20099, 11303},{10614, 27938, 25729, 15097, 9464}};

double fracBackground[nPtBins][nCPMBins]={{0.0311423, 0.049552, 0.0699898, 0.0911559, 0.122637},{0.0326477, 0.0416861, 0.0516607, 0.0644685, 0.0741538}};

double meanRap[nPtBins][nCPMBins]={{0.537962, 0.533339, 0.532077, 0.532779, 0.529773},{0.537216, 0.534431, 0.532949, 0.535576, 0.533201}};

int rap1entries[nPtBins][nCPMBins]={{15486, 29781, 22823, 11696, 6630},{6126, 16335, 14992, 8785, 5528}};

int rap2entries[nPtBins][nCPMBins]={{11398, 21475, 16410, 8403, 4672},{4488, 11603, 10737, 6312, 3936}};

//Total Number of Signal Events in safe region: 237617

const int nEffs=3;
const int FidCuts=3;

}