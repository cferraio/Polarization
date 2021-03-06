#!/bin/sh

storagedir=$3
homedir=$4
setptbin=$5
setcpmbin=$6
setbgframe=$7

export VO_CMS_SW_DIR=/sharesoft/cmssw #comment out for non-condor
. $VO_CMS_SW_DIR/cmsset_default.sh #comment out for non-condor
cd /home/ferraioc/Polarization/CMSSW_4_4_2/src/MODIFIED/CMS/Polarization/UpsilonPol2011/macros/polFit #comment out for non-condor
eval `scramv1 runtime -sh` #comment out for non-condor

echo "storage dir: $storagedir"
echo "home dir: $homedir"
echo "ptbin: $setptbin"
echo "cpmbin: $setcpmbin"

########## INPUTS ##########

nState=1

JobID=15to50

nGenerations=50

rapBinMin=1
rapBinMax=1
ptBinMin=$setptbin
ptBinMax=$setptbin
cpmBinMin=$setcpmbin
cpmBinMax=$setcpmbin


polScenSig=3
polScenBkg=$setbgframe
frameSig=3
frameBkg=3

nEff=1030
UseMCeff=false
nDileptonEff=1
UseMCDileptoneff=false
nRhoFactor=1

useAmapApproach=false
nAmap=32104                     #frame/state/sigma/ID ( ID= 2 digits )
nDenominatorAmap=105 		    #the number here corresponds to the same notation as nEff
 
FidCuts=11

nSample=10000
nSkipGen=0

#GENERATION SETTINGS
ConstEvents=50000
UseConstEv=false

UseDifferingEff=false
nEffRec=1030
UseMCReceff=false
nDileptonEffRec=1
UseMCDileptonReceff=false
nRecRhoFactor=1

gen=true
rec=true
fit=true
plot=true
deletePseudoData=true

MPValgo=3 		#1...mean,2...gauss,3...gauss-loop with chi2<2
nSigma=1
NewAccCalc=false


########################################

cd ..
cd ..
basedir=`pwd`
cd macros/polFit
#storagedir=`more storagedir`/ToyMC #please define the directory storagedir in the file macros/polFit/storagedir

echo "basedir = $basedir"
echo "storage dir is ${storagedir}"
echo "base dir is ${basedir}"


touch polGenRecFitPlot.cc
make

ScenDir=Sig_frame${frameSig}scen${polScenSig}_Bkg_frame${frameBkg}scen${polScenBkg}

mkdir ${storagedir}
mkdir ${storagedir}/${JobID}
mkdir ${storagedir}/${JobID}/${ScenDir}
cp ${basedir}/macros/polFit/polGenRecFitPlot ${storagedir}/${JobID}/${ScenDir}/polGenRecFitPlot
cp ${basedir}/macros/polFit/polGen.C ${storagedir}/${JobID}/${ScenDir}/polGen.C
cp ${basedir}/macros/polFit/polRec.C ${storagedir}/${JobID}/${ScenDir}/polRec.C
cp ${basedir}/macros/polFit/polFit.C ${storagedir}/${JobID}/${ScenDir}/polFit.C
cp ${basedir}/macros/polFit/polPlot.C ${storagedir}/${JobID}/${ScenDir}/polPlot.C

cd ${storagedir}/${JobID}/${ScenDir}
cp ${basedir}/macros/polFit/runToyMC.sh .

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
nGen_=$((nGen_+1))
while [ $nGen_ -le ${nGenerations} ]
do

plot=${plot}

cp ${storagedir}/${JobID}/${ScenDir}/polGenRecFitPlot ${storagedir}/${JobID}/${ScenDir}/polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm}_Gen${nGen_}

if [ ${nGen_} -eq 1 ]
then
plot=true
fi

./polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm}_Gen${nGen_} ${nGen_}ThisGen ${JobID}=JobID ${storagedir}=storagedir ${basedir}=basedir ${nGenerations}nGenerations ${polScenSig}polScenSig ${frameSig}frameSig ${polScenBkg}polScenBkg ${frameBkg}frameBkg ${rap_}rapBinMin ${rap_}rapBinMax ${pT_}ptBinMin ${pT_}ptBinMax ${cpm_}cpmBinMin ${cpm_}cpmBinMax ${nEff}nEff ${nDileptonEff}nDiEff ${nEffRec}nRecEff ${nDileptonEffRec}nRecDiEff ${FidCuts}FidCuts ${nSample}nSample ${ConstEvents}ConstEvents ${nSkipGen}nSkipGen UseConstEv=${UseConstEv} gen=${gen} rec=${rec} fit=${fit} plot=${plot} UseDifferingEff=${UseDifferingEff} UseMCeff=${UseMCeff} UseMCReceff=${UseMCReceff} UseMCDileptoneff=${UseMCDileptoneff} UseMCDileptonReceff=${UseMCDileptonReceff}  ${nRhoFactor}nRhoFactor ${nRecRhoFactor}nRecRhoFactor ${MPValgo}MPValgo ${nSigma}nSigma ${nState}nState NewAccCalc=${NewAccCalc} deletePseudoData=${deletePseudoData} useAmapApproach=${useAmapApproach} ${nAmap}nAmap ${nDenominatorAmap}nDenominatorAmap

rm polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm_}_Gen${nGen_}

nGen_=$((nGen_+1))
done
cpm_=$((cpm_+1))
done
pT_=$((pT_+1))
done
rap_=$((rap_+1))
done

#rm polGen.C 
#rm polRec.C 
#rm polFit.C 
#rm polPlot.C 