#!/bin/sh

homedir=`pwd`
cd ..
cd ..
basedir=`pwd`
cd macros/polFit
storagedir=`more storagedir`/Data #please define the directory storagedir in the file macros/polFit/storagedir
datadir_Start=${basedir}/macros/DataFiles

echo "basedir = $basedir"
echo "storage dir is ${storagedir}"
echo "base dir is ${basedir}"

########## INPUTS ##########

#Batch submission system: 0/1
useBatch=0

fracL=72 #in percent #MC closure: 25 for data sigmas, 50 for MC sigmas
nSigma=1.00 #needed in 2 decimal accuracy (x.yz)

for nState in 1;do

JobID=LambdaDiffs_2011_actual #Please define nSigma and fracL yourself in the JobID, if needed

rapBinMin=1
rapBinMax=1
ptBinMin=1
ptBinMax=1
cpmBinMin=2
cpmBinMax=2

FidCuts=11

nEff=1				#1101 MCtruthFineEta, 1080 MCTnPparam      #1030=soft-1060=tight-1070=mixed-111=soft-112=tight
UseMCeff=false

nDileptonEff=1
UseMCDileptoneff=true

nRhoFactor=331

useAmapApproach=false
nAmap=1                    #frame/state/sigma/ID ( ID= 2 digits )
nDenominatorAmap=1		    	#the number here corresponds to the same notation as nEff

nSample=15000

nFits=1
nSkipGen=0

DataID=_LambdaDiffs_2011

MPValgo=3 		#1...mean,2...gauss,3...gauss-loop with chi2<2

runCorrectionMap=true


########################################

useCentralFracL=0

if [ $useCentralFracL -eq 1 ]
then
if [ $nState -eq 1 ]
then
fracL=72 #72
fi
if [ $nState -eq 2 ]
then
fracL=46 #46
fi
if [ $nState -eq 3 ]
then
fracL=30 #30
fi
fi

datadir=${datadir_Start}/SetOfCuts${FidCuts}${DataID}/AllStates_${nSigma}Sigma_FracLSB${fracL}Percent

TreeID=${nState}SUps

cd ${homedir}


polScenSig=3
polScenBkg=3
frameSig=1
frameBkg=1
ConstEvents=15000
UseConstEv=true
nGenerations=${nFits}
gen=false
rec=false
fit=true
plot=true
NewAccCalc=false

touch polGenRecFitPlot.cc
make

ScenDir=Default_ScenDir
mkdir ${storagedir}
mkdir ${storagedir}/${JobID}

cp ${basedir}/macros/polFit/polGenRecFitPlot ${storagedir}/${JobID}/polGenRecFitPlot
cp ${basedir}/macros/polFit/polGen.C ${storagedir}/${JobID}/polGen.C
cp ${basedir}/macros/polFit/polRec.C ${storagedir}/${JobID}/polRec.C
cp ${basedir}/macros/polFit/polFit.C ${storagedir}/${JobID}/polFit.C
cp ${basedir}/macros/polFit/polPlot.C ${storagedir}/${JobID}/polPlot.C

cd ${storagedir}/${JobID}
cp ${basedir}/macros/polFit/runDataFits.sh .


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
nMaxGen=$((nGenerations+nSkipGen))
while [ $nGen_ -le $nMaxGen ]
do

if [ $useBatch -eq 0 ]
then

resultfilename=resultsMerged_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.root
nActualGen=$((nGen_-nSkipGen))
if [ $nSkipGen -ge 0 ]
then
if [ $nActualGen -eq 1 ]
then
cp results_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.root ${resultfilename}
fi
fi

fi

cp ${storagedir}/${JobID}/polGenRecFitPlot ${storagedir}/${JobID}/polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm_}
./polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm_} ${nGen_}ThisGen ${JobID}=JobID ${storagedir}=storagedir ${basedir}=basedir ${nGenerations}nGenerations ${polScenSig}polScenSig ${frameSig}frameSig ${polScenBkg}polScenBkg ${frameBkg}frameBkg ${rap_}rapBinMin ${rap_}rapBinMax ${pT_}ptBinMin ${pT_}ptBinMax ${cpm_}cpmBinMin ${cpm_}cpmBinMax ${nEff}nEff ${nDileptonEff}nDiEff ${FidCuts}FidCuts ${nSample}nSample ${ConstEvents}ConstEvents ${nSkipGen}nSkipGen UseConstEv=${UseConstEv} gen=${gen} rec=${rec} fit=${fit} plot=${plot} ${TreeID}=TreeID ${datadir}=realdatadir UseMCeff=${UseMCeff} UseMCDileptoneff=${UseMCDileptoneff} ${nRhoFactor}nRhoFactor ${MPValgo}MPValgo NewAccCalc=${NewAccCalc} useAmapApproach=${useAmapApproach} ${nAmap}nAmap ${nDenominatorAmap}nDenominatorAmap useBatch=${useBatch} runCorrectionMap=${runCorrectionMap} 
rm polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm_}




if [ $useBatch -eq 0 ]
then

mv results_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.root results_Fit${nGen_}_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.root

if [ $nGen_ -eq 1 ]
then
cp results_Fit${nGen_}_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.root ${resultfilename}
fi

if [ $nGen_ -ge 2 ]
then
mv ${resultfilename} BUFFER_${resultfilename}
hadd -f ${resultfilename} BUFFER_${resultfilename} results_Fit${nGen_}_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.root
rm BUFFER_${resultfilename}
fi

#cp ${resultfilename} results_MergedUpToFit${nGen_}_${nState}SUps_rap${rap_}_pT${pT_}.root

fi

nGen_=$((nGen_+1))
done

if [ $useBatch -eq 0 ]
then

mv ${resultfilename} results_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.root

cp ${storagedir}/${JobID}/polGenRecFitPlot ${storagedir}/${JobID}/polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm_}
./polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm_} ${nGen_}ThisGen ${JobID}=JobID ${storagedir}=storagedir ${basedir}=basedir ${nGenerations}nGenerations ${polScenSig}polScenSig ${frameSig}frameSig ${polScenBkg}polScenBkg ${frameBkg}frameBkg ${rap_}rapBinMin ${rap_}rapBinMax ${pT_}ptBinMin ${pT_}ptBinMax ${cpm_}cpmBinMin ${cpm_}cpmBinMax ${nEff}nEff ${nDileptonEff}nDiEff ${FidCuts}FidCuts ${nSample}nSample ${ConstEvents}ConstEvents ${nSkipGen}nSkipGen UseConstEv=${UseConstEv} gen=false rec=false fit=false plot=true ${TreeID}=TreeID ${datadir}=realdatadir UseMCeff=${UseMCeff} UseMCDileptoneff=${UseMCDileptoneff} ${nRhoFactor}nRhoFactor ${MPValgo}MPValgo scalePlots=true NewAccCalc=${NewAccCalc} useAmapApproach=${useAmapApproach} ${nAmap}nAmap ${nDenominatorAmap}nDenominatorAmap runCorrectionMap=${runCorrectionMap} 
rm polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm_} 

fi

cpm_=$((cpm_+1))
done
pT_=$((pT_+1))
done
rap_=$((rap_+1))
done


done

rm *.so
rm *.d

mkdir ../tmp

