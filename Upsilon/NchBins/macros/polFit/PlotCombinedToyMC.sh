#!/bin/sh

########## INPUTS ##########

nState=3

JobID=pTBGSubRatioIssue_e

nGenerations=10
MergeFiles=1

rapBinMin=1
rapBinMax=1
ptBinMin=2
ptBinMax=2
cpmBinMin=5
cpmBinMax=5

polScenSig=3
polScenBkg=9
frameSig=3
frameBkg=3

MPValgo=3 		#1...mean,2...gauss,3...gauss-loop with chi2<2
nSigma=1


########################################

gen=false
rec=false
fit=false
plot=true

NewAccCalc=true
nEff=1030
UseMCeff=false
nDileptonEff=1
UseMCDileptoneff=false
nRhoFactor=1

FidCuts=11

nSample=50000
nSkipGen=0

#GENERATION SETTINGS
ConstEvents=50000
UseConstEv=true

UseDifferingEff=false
nEffRec=1030
UseMCReceff=false
nDileptonEffRec=1
UseMCDileptonReceff=false
nRecRhoFactor=1

TreeID=${nState}SUps

##############################################

cd ..
cd ..
basedir=`pwd`
cd macros/polFit
storagedir=`more storagedir`/ToyMC #please define the directory storagedir in the file macros/polFit/storagedir



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


resultfilename=resultsMerged_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.root


GenResultName=${storagedir}/${JobID}/${ScenDir}/rap${rap_}_pT${pT_}_cpm${cpm_}/Generation${nGen_}/results.root

if [ $MergeFiles -eq 1 ]
then

if [ $nGen_ -eq 1 ]
then
cp ${GenResultName} ${resultfilename}
fi

if [ $nGen_ -ge 2 ]
then
mv ${resultfilename} BUFFER_${resultfilename}
hadd -f ${resultfilename} BUFFER_${resultfilename} ${GenResultName}
rm BUFFER_${resultfilename}
fi

fi



nGen_=$((nGen_+1))
done

if [ $MergeFiles -eq 1 ]
then
mv ${resultfilename} ${storagedir}/${JobID}/results_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.root
fi

cp ${storagedir}/${JobID}/${ScenDir}/polGenRecFitPlot ${storagedir}/${JobID}/${ScenDir}/polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm_}
./polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm_} ${nGen_}ThisGen ${JobID}=JobID/${ScenDir} ${storagedir}=storagedir ${basedir}=basedir ${nGenerations}nGenerations ${polScenSig}polScenSig ${frameSig}frameSig ${polScenBkg}polScenBkg ${frameBkg}frameBkg ${rap_}rapBinMin ${rap_}rapBinMax ${pT_}ptBinMin ${pT_}ptBinMax ${cpm_}cpmBinMin ${cpm_}cpmBinMax ${nEff}nEff ${nDileptonEff}nDiEff ${FidCuts}FidCuts ${nSample}nSample ${ConstEvents}ConstEvents ${nSkipGen}nSkipGen UseConstEv=${UseConstEv} gen=false rec=false fit=false plot=${plot} ${TreeID}=TreeID ${datadir}=realdatadir UseMCeff=${UseMCeff} UseMCDileptoneff=${UseMCDileptoneff} ${nRhoFactor}nRhoFactor ${MPValgo}MPValgo scalePlots=true NewAccCalc=${NewAccCalc}
rm polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm_}

cpm_=$((cpm_+1))
done
pT_=$((pT_+1))
done
rap_=$((rap_+1))
done


