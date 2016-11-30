#!/bin/sh

source /cvmfs/sft.cern.ch/lcg/app/releases/ROOT/5.34.05/x86_64-slc5-gcc43-opt/root/bin/thisroot.sh                                     
source /cvmfs/sft.cern.ch/lcg/app/releases/ROOT/5.34.05/x86_64-slc5-gcc43-opt/root/bin/setxrd.sh /cvmfs/sft.cern.ch/lcg/external/xrootd/3.2.4/x86_64-slc5-gcc46-opt/


homedir=/home/ferraioc/PolNew/CMSSW_5_3_20/src/JPsi_Nch_Polarization/NchInt/macros/polFit

JobID=tests

cd ${homedir}
cd ..
cd ..
basedir=$PWD
cd macros/polFit
storagedir=`more storagedir`/ToyMC

nState=4


CONDOR_JOB="runtoyscondor.jdl"
n=0
ngen=20

for polsig in 3 #3=unpolarized
do
for frameSig in 1
do
for polScenBkg in 3 #3=unpolarized
do
for frameBkg in 1
do

	ScenDir=Sig_frame${frameSig}scen${polScenSig}_Bkg_frame${frameBkg}scen${polScenBkg}
	mkdir -p ${storagedir}/${JobID}/${ScenDir}
	
cp ${basedir}/macros/polFit/polGenRecFitPlot.cc ${storagedir}/${JobID}/${ScenDir}/polGenRecFitPlot.cc
cp ${basedir}/macros/polFit/polRapPtPlot.cc ${storagedir}/${JobID}/${ScenDir}/polRapPtPlot.cc
cp ${basedir}/macros/polFit/PlotFinalResults.cc ${storagedir}/${JobID}/${ScenDir}/PlotFinalResults.cc
cp ${basedir}/macros/polFit/Makefile ${storagedir}/${JobID}/${ScenDir}/Makefile
cp ${basedir}/macros/polFit/polGen.C ${storagedir}/${JobID}/${ScenDir}/polGen.C
cp ${basedir}/macros/polFit/polRec.C ${storagedir}/${JobID}/${ScenDir}/polRec.C
cp ${basedir}/macros/polFit/polFit.C ${storagedir}/${JobID}/${ScenDir}/polFit.C
cp ${basedir}/macros/polFit/polPlot.C ${storagedir}/${JobID}/${ScenDir}/polPlot.C

cp ../../interface/rootIncludes.inc ${storagedir}/${JobID}/${ScenDir}/rootIncludes.inc
cp ../../interface/commonVar_Psi$[nState-3]S.h ${storagedir}/${JobID}/${ScenDir}/commonVar.h
cp ../../interface/ToyMC_Psi$[nState-3]S.h ${storagedir}/${JobID}/${ScenDir}/ToyMC.h
cp ../../interface/effsAndCuts_Psi$[nState-3]S.h ${storagedir}/${JobID}/${ScenDir}/effsAndCuts.h

cp ../../interface/rootIncludes.inc ${storagedir}/${JobID}/${ScenDir}/rootIncludes.inc


cd ${storagedir}/${JobID}/${ScenDir}
cp ${basedir}/macros/polFit/runToyMC.sh .

touch polGenRecFitPlot.cc
make

cd ${homedir}
while [[ $n -le $ngen-1 ]]
do
#for polsig in 1 2 4 5	
#for pt in 2
#for rap in 1 2
#do
for pt in 1 2 3 4 5
do
#		sleep 1
		cp runcondorToys.jdl $CONDOR_JOB
		echo "$storagedir $homedir $pt $n $polsig $polScenBkg $frameSig $frameBkg $JobID $rap" >> $CONDOR_JOB 
#		echo "$pt $n " >> $CONDOR_JOB 
		echo "Queue 1" >> $CONDOR_JOB	
		condor_submit $CONDOR_JOB

#done
done
n=$(( n+1 ))
done
done
done
done 
done