#!/bin/sh
#source /cvmfs/cms.cern.ch/cmsset_default.csh
#cd /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit #comment out for non-condor
#eval `scramv1 runtime -sh` #comment out for non-condor

export VO_CMS_SW_DIR=/sharesoft/cmssw #comment out for non-condor
. $VO_CMS_SW_DIR/cmsset_default.sh #comment out for non-condor
cd /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit #comment out for non-condor
eval `scramv1 runtime -sh` #comment out for non-condor

source /cvmfs/sft.cern.ch/lcg/app/releases/ROOT/5.34.05/x86_64-slc5-gcc43-opt/root/bin/thisroot.sh                                     
source /cvmfs/sft.cern.ch/lcg/app/releases/ROOT/5.34.05/x86_64-slc5-gcc43-opt/root/bin/setxrd.sh /cvmfs/sft.cern.ch/lcg/external/xrootd/3.2.4/x86_64-slc5-gcc46-opt/

########## INPUTS ##########

storagedir=/data/users/ferraioc/Polarization/JPsi/NchBins 
homedir=/home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit
setcpmbin=$2
setptbin=$1
nState=$4
JobID=$5
polScenSig=3
polScenBkg=3
frameSig=1
frameBkg=1

echo "Vertex eff"
echo "storage dir: $storagedir"
echo "home dir: $homedir"
echo "ptbin: $setptbin"
echo "cpmbin: $setcpmbin"
echo "nState: $nState"
echo "JobID: $JobID"
echo "skip gen: $3"



nGenerations=1

rapBinMin=1
rapBinMax=1
ptBinMin=$setptbin
ptBinMax=$setptbin
cpmBinMin=$setcpmbin
cpmBinMax=$setcpmbin


nEff=1080 
UseMCeff=true
nDileptonEff=1
UseMCDileptoneff=true
nRhoFactor=1

useAmapApproach=false       #if false, the next two lines do not matter
nAmap=32104                 #frame/state/sigma/ID ( ID= 2 digits )
nDenominatorAmap=1 		    #the number here corresponds to the same notation as nEff
 
FidCuts=11

nSample=10000
nSkipGen=$3

#GENERATION SETTINGS
ConstEvents=200000
UseConstEv=true #if false, the number of events is taken from ToyMC.h

UseDifferingEff=true #if false, the next five lines do not matter
nEffRec=1080  #1101 is mc for t&p
UseMCReceff=true
nDileptonEffRec=222
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

#homedir=homedir

storagedir=${storagedir}/ToyMC

ScenDir=Sig_frame${frameSig}scen${polScenSig}_Bkg_frame${frameBkg}scen${polScenBkg}

cd ${homedir}
cd ..
cd ..
basedir=$PWD
cd ${storagedir}/${JobID}/${ScenDir}


rap_=${rapBinMin}
while [ $rap_ -le ${rapBinMax} ]
do
pT_=${ptBinMin}
while [ $pT_ -le ${ptBinMax} ]
do
cpm_=${cpmBinMin}
while [ $cpm_ -le ${cpmBinMax} ]
do


nGen_=${nSkipGen}
nGen_=$[nGen_+1]
nMaxGen=$[nGenerations+nSkipGen]
while [ $nGen_ -le $nMaxGen ]
do

plot=${plot}

#if [ ${nGen_} -eq 1 ]
#then
#plot=true
#fi


cp polGenRecFitPlot polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm_}_Gen${nGen_}
./polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm_}_Gen${nGen_} ${nGen_}ThisGen ${JobID}=JobID ${storagedir}=storagedir ${basedir}=basedir ${nGenerations}nGenerations ${polScenSig}polScenSig ${frameSig}frameSig ${polScenBkg}polScenBkg ${frameBkg}frameBkg ${rap_}rapBinMin ${rap_}rapBinMax ${pT_}ptBinMin ${pT_}ptBinMax ${cpm_}cpmBinMin ${cpm_}cpmBinMax ${nEff}nEff ${nDileptonEff}nDiEff ${nEffRec}nRecEff ${nDileptonEffRec}nRecDiEff ${FidCuts}FidCuts ${nSample}nSample ${ConstEvents}ConstEvents ${nSkipGen}nSkipGen UseConstEv=${UseConstEv} gen=${gen} rec=${rec} fit=${fit} plot=${plot} UseDifferingEff=${UseDifferingEff} UseMCeff=${UseMCeff} UseMCReceff=${UseMCReceff} UseMCDileptoneff=${UseMCDileptoneff} UseMCDileptonReceff=${UseMCDileptonReceff}  ${nRhoFactor}nRhoFactor ${nRecRhoFactor}nRecRhoFactor ${MPValgo}MPValgo ${nSigma}nSigma ${nState}nState NewAccCalc=${NewAccCalc} deletePseudoData=${deletePseudoData} useAmapApproach=${useAmapApproach} ${nAmap}nAmap ${nDenominatorAmap}nDenominatorAmap
rm polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm_}_Gen${nGen_}

nGen_=$[nGen_+1]
done
cpm_=$[cpm_+1]
done
pT_=$[pT_+1]
done
rap_=$[rap_+1]
done


#rm polGen.C 
#rm polRec.C 
#rm polFit.C 
#rm polPlot.C