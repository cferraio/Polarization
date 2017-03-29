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
int MarkerStyle[4][3]={{0,0,0},{0,33,27},{0,20,24},{0,21,25}}; // for each state, rapBin (1= closed, 2=open)
//int MarkerColor[4] = {0,1,2,3};//{0,600,632,418}; // for each frame
int MarkerColor[4] = {1,1,1,1};//{0,600,632,418}; // for each frame
double MarkerSize[4][3]={{0,0,0},{0,2.75,2.75},{0,1.65,1.65},{0,1.65,1.65}};// for each state, rapBin

const int nPtBins=2;
const int nRapBins=1;
/const int nCPMBins=5;
//const int nCPMBins=4;

//From FracL 72:
//Upsilon(1):

double ptCentre[nPtBins][nCPMBins]={{12.0228, 12.1348, 12.1725, 12.1842, 12.2026},{19.0335, 19.9208, 20.6229, 20.9788, 21.6947}};

double cpmCentre[nPtBins][nCPMBins]={{6.61274, 14.9849, 24.5775, 34.4264, 46.9469},{6.95899, 15.2337, 24.6783, 34.4796, 46.9283}};

int numEvents[nPtBins][nCPMBins]={{27565, 52614, 40347, 20715, 11686},{11029, 29429, 27493, 16219, 10329}};

double fracBackground[nPtBins][nCPMBins]={{0.031047, 0.0497481, 0.0699837, 0.0912297, 0.122446},{0.0330525, 0.0426101, 0.0518053, 0.065006, 0.0748603}};

double meanRap[nPtBins][nCPMBins]={{0.537461, 0.533219, 0.53185, 0.532651, 0.529848},{0.536991, 0.5351, 0.533449, 0.535757, 0.532271}};

int rap1entries[nPtBins][nCPMBins]={{15890, 30586, 23495, 12054, 6849},{6364, 17168, 16001, 9431, 6051}};

int rap2entries[nPtBins][nCPMBins]={{11674, 22027, 16852, 8660, 4837},{4665, 12260, 11492, 6788, 4277}};

//Total Number of Signal Events in safe region: 247426

//From FracL 46:
//Upsilon(2):
/*
double ptCentre[nPtBins][nCPMBins]={{12.0358, 12.1753, 12.2043, 12.2138, 12.2317},{19.2129, 20.2581, 21.0987, 21.8062, 22.0322}};

double cpmCentre[nPtBins][nCPMBins]={{6.56058, 14.9981, 24.5752, 34.4017, 46.8499},{6.97436, 15.2225, 24.7254, 34.531, 46.9052}};

int numEvents[nPtBins][nCPMBins]={{10422, 18649, 13376, 6520, 3554},{4710, 12744, 11670, 6519, 4102}};

double fracBackground[nPtBins][nCPMBins]={{0.0714052, 0.122257, 0.178745, 0.237287, 0.313738},{0.0686949, 0.0878138, 0.10694, 0.142671, 0.166383}};

double meanRap[nPtBins][nCPMBins]={{0.533881, 0.532218, 0.526217, 0.524155, 0.527212},{0.540716, 0.541311, 0.535719, 0.534004, 0.540129}};

int rap1entries[nPtBins][nCPMBins]={{6073, 10929, 7870, 3889, 2104},{2694, 7268, 6789, 3782, 2338}};

int rap2entries[nPtBins][nCPMBins]={{4348, 7719, 5505, 2631, 1450},{2016, 5475, 4880, 2736, 1763}};
*/
//Total Number of Signal Events in safe region: 92266

//FracL 30:
//Upsilon(3):
/*
double ptCentre[nPtBins][nCPMBins]={{12.0678, 12.1891, 12.2096, 12.2133, 12.1781},{19.5425, 20.5149, 21.3914, 21.9096, 22.6345}};

double cpmCentre[nPtBins][nCPMBins]={{6.52768, 14.9376, 24.533, 34.3689, 46.9187},{6.90424, 15.1098, 24.6705, 34.4013, 46.982}};

int numEvents[nPtBins][nCPMBins]={{6721, 11085, 7748, 3532, 1792},{3352, 8666, 7857, 4185, 2563}};

double fracBackground[nPtBins][nCPMBins]={{0.101791, 0.181914, 0.263353, 0.357972, 0.468982},{0.0909888, 0.118699, 0.1466, 0.201769, 0.238047}};

double meanRap[nPtBins][nCPMBins]={{0.528679, 0.530572, 0.526607, 0.531877, 0.523459},{0.527046, 0.542903, 0.543278, 0.533946, 0.534393}};

int rap1entries[nPtBins][nCPMBins]={{3959, 6485, 4612, 2096, 1087},{1985, 4960, 4466, 2426, 1489}};

int rap2entries[nPtBins][nCPMBins]={{2761, 4599, 3135, 1436, 705},{1367, 3705, 3390, 1759, 1074}};
*/
//Total Number of Signal Events in safe region: 57501

//FracL 30, 4 CPM bins:
//Upsilon(3):
/*
double ptCentre[nPtBins][nCPMBins]={{12.0678, 12.1891, 12.2096, 12.1999},{19.5425, 20.5149, 21.3914, 22.1928}};

double cpmCentre[nPtBins][nCPMBins]={{6.52768, 14.9376, 24.533, 39.1316},{6.90424, 15.1098, 24.6705, 39.3129}};

int numEvents[nPtBins][nCPMBins]={{6721, 11085, 7748, 5320},{3352, 8666, 7857, 6741}};

double fracBackground[nPtBins][nCPMBins]={{0.101791, 0.181914, 0.263353, 0.400455},{0.0909888, 0.118699, 0.1466, 0.217272}};

double meanRap[nPtBins][nCPMBins]={{0.528679, 0.530572, 0.526607, 0.528732},{0.527046, 0.542903, 0.543278, 0.534039}};

int rap1entries[nPtBins][nCPMBins]={{3959, 6485, 4612, 3184},{1985, 4960, 4466, 3912}};

int rap2entries[nPtBins][nCPMBins]={{2761, 4599, 3135, 2136},{1367, 3705, 3390, 2829}};
*/
const int nEffs=3;
const int FidCuts=3;

}
