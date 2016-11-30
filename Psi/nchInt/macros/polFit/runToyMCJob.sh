#!/bin/sh

export VO_CMS_SW_DIR=/sharesoft/cmssw #comment out for non-condor
. $VO_CMS_SW_DIR/cmsset_default.sh #comment out for non-condor
cd /home/ferraioc/PolNew/CMSSW_5_3_20/src/JPsi_Nch_Polarization/NchInt/macros/polFit
#comment out for non-condor
eval `scramv1 runtime -sh` #comment out for non-condor

source /cvmfs/sft.cern.ch/lcg/app/releases/ROOT/5.34.05/x86_64-slc5-gcc43-opt/root/bin/thisroot.sh                                     
source /cvmfs/sft.cern.ch/lcg/app/releases/ROOT/5.34.05/x86_64-slc5-gcc43-opt/root/bin/setxrd.sh /cvmfs/sft.cern.ch/lcg/external/xrootd/3.2.4/x86_64-slc5-gcc46-opt/

#### following will be changed by "launchFitToy.sh" ####
# HOMEDIR
# NState 
# RapBinMin
# RapBinMax
# PtBinMin
# PtBinMax
# NSkipGen
# PolScenSig
# PolScenBkg
# FrameSig
# FrameBkg
# USEConstEv
######################################### 

########## INPUTS ##########

storagedir=$3
homedir=$4
setptbin=$5
setgen=$6
scensig=$7
rapBinMin=2
rapBinMax=2
#rapBinMin=${12}
#rapBinMax=${12}
ptBinMin=$setptbin
ptBinMax=$setptbin

polScenSig=$scensig
polScenBkg=$8
frameSig=$9
frameBkg=${10}
JobID=${11}



echo "storage dir: $storagedir"
echo "home dir: $homedir"
echo "ptbin: $setptbin"
echo "rapbin: ${12}"
echo "scensig: $scensig"
echo "scenbkg: $polScenBkg"
echo "frameSig: $frameSig"
echo "frameBkg: $frameBkg"
echo "jobid: $JobID"

nState=4
#NKevent=NKEVENT

#JobID=ToyMC_Psi$[nState-3]S_Eff_pTshift_minus_8Jan2013
#JobID=ToyMC_Psi$[nState-3]S_13Dec2012_100K
#JobID=ToyMC_Framework2_Chi_c2_12Jun2016
#
#JobID=ToyMC_Psi$[nState-3]S_13Dec2012



nGenerations=1



nEff=1101  #MC-truth
#nEff=1091
#nEff=1062
UseMCeff=true
nDileptonEff=1
UseMCDileptoneff=true
nRhoFactor=1
 
FidCuts=11

useAmapApproach=false       #if false, the next two lines do not matter
nAmap=32104                 #frame/state/sigma/ID ( ID= 2 digits )
nDenominatorAmap=1101 		    #the number here corresponds to the same notation as nEff


nSample=10000
nSkipGen=$setgen

#GENERATION SETTINGS
ConstEvents=200000
UseConstEv=true #if false, the number of events is taken from ToyMC.h

UseDifferingEff=false #if false, the next five lines do not matter
nEffRec=1060 #1101
UseMCReceff=false
nDileptonEffRec=1
UseMCDileptonReceff=true
nRecRhoFactor=1

gen=true
rec=true
fit=true
plot=false
deletePseudoData=false

MPValgo=3 		#1...mean,2...gauss,3...gauss-loop with chi2<2
nSigma=1
NewAccCalc=false


########################################

#homedir=HOMEDIR
cd ${homedir}
cd ..
cd ..
basedir=$PWD
cd macros/polFit
storagedir=`more storagedir`/ToyMC #please define the directory storagedir in the file macros/polFit/storagedir
#storagedir=${basedir}/Psi/ToyMC

ScenDir=Sig_frame${frameSig}scen${polScenSig}_Bkg_frame${frameBkg}scen${polScenBkg}

mkdir -p ${storagedir}/${JobID}/${ScenDir}



#cd ${storagedir}/${JobID}/${ScenDir}
#cp ${basedir}/macros/polFit/runToyMC.sh .

#touch polGenRecFitPlot.cc
#make

rap_=${rapBinMin}
while [ $rap_ -le ${rapBinMax} ]
do
pT_=${ptBinMin}
while [ $pT_ -le ${ptBinMax} ]
do

nGen_=${nSkipGen}
nGen_=$[nGen_+1]
nMaxGen=$[nGenerations+nSkipGen]
while [ $nGen_ -le $nMaxGen ]
do

plot=${plot}

if [ ${nGen_} -eq 1 ]
then
plot=true
fi


cp polGenRecFitPlot polGenRecFitPlot_rap${rap_}_pt${pT_}_Gen${nGen_}
./polGenRecFitPlot_rap${rap_}_pt${pT_}_Gen${nGen_} ${nGen_}ThisGen ${JobID}=JobID ${storagedir}=storagedir ${basedir}=basedir ${nGenerations}nGenerations ${polScenSig}polScenSig ${frameSig}frameSig ${polScenBkg}polScenBkg ${frameBkg}frameBkg ${rap_}rapBinMin ${rap_}rapBinMax ${pT_}ptBinMin ${pT_}ptBinMax ${nEff}nEff ${nDileptonEff}nDiEff ${nEffRec}nRecEff ${nDileptonEffRec}nRecDiEff ${FidCuts}FidCuts ${nSample}nSample ${ConstEvents}ConstEvents ${nSkipGen}nSkipGen UseConstEv=${UseConstEv} gen=${gen} rec=${rec} fit=${fit} plot=${plot} UseDifferingEff=${UseDifferingEff} UseMCeff=${UseMCeff} UseMCReceff=${UseMCReceff} UseMCDileptoneff=${UseMCDileptoneff} UseMCDileptonReceff=${UseMCDileptonReceff}  ${nRhoFactor}nRhoFactor ${nRecRhoFactor}nRecRhoFactor ${MPValgo}MPValgo ${nSigma}nSigma ${nState}nState NewAccCalc=${NewAccCalc} deletePseudoData=${deletePseudoData} useAmapApproach=${useAmapApproach} ${nAmap}nAmap ${nDenominatorAmap}nDenominatorAmap
rm polGenRecFitPlot_rap${rap_}_pt${pT_}_Gen${nGen_}

nGen_=$[nGen_+1]
done
pT_=$[pT_+1]
done
rap_=$[rap_+1]
done


#rm polGen.C 
#rm polRec.C 
#rm polFit.C 
#rm polPlot.C 

