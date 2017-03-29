#!/bin/sh

homedir=`pwd`
cd ..
cd ..
basedir=`pwd`
cd macros/polFit
storagedir=`more storagedir`/Data #please define the directory storagedir in the file macros/polFit/storagedir

########## INPUTS ##########

for nState in 3;do
#for JobID1 in Data_TowardsPRL_Aug11_FinalResults_3Sigma;do #this is the systematic error!!! #ifCorrectCentralResultsForBias: here is the central
#for JobID1 in MCclosure_Aug11_Ups3S_10MCSig;do #this is the systematic error!!! #ifCorrectCentralResultsForBias: here is the central
#for JobID1 in Data_TowardsPRL_Aug11_FinalResults_1Sigma;do #this is the systematic error!!! #ifCorrectCentralResultsForBias: here is the central
#for JobID1 in GreatCPMRun_4CPMBins_Systematics_sig1_fracL59; do
#for JobID1 in GreatCPMRun2_4CPMBins; do
for JobID1 in cutNPriVtx_smallerpT2_bgeL; do

SystID=cutNPriVtx_smallerpT2_BGE_forsystplot #BiasCorrectedResults #MassSigmaDep

#JobID2=BiasCorrection_1S2S3SAug12_3Sig   #this is the default!!! #BC: here is the 1/3 sigma
#JobID2=MCclosure_Aug11_Ups3S_3DataSig   #this is the default!!! #BC: here is the 1/3 sigma
JobID2=cutNPriVtx_smallerpT2   #this is the default!!! #BC: here is the 1/3 sigma
#JobID2=GreatCPMRun2_4CPMBins_fracL59

ptBinMin=2
ptBinMax=2
cpmBinMin=1
cpmBinMax=5

statErrConsideration=false

########################################

cd ${homedir}

touch EvaluateSyst.cc
make

mkdir Systematics
mkdir Systematics/${SystID}

SystDir=Systematics/${SystID}/${JobID1}_TO_${JobID2}

mkdir ${SystDir}


./EvaluateSyst ${JobID1}=JobID1 ${JobID2}=JobID2 ${SystDir}=SystDir ${storagedir}=storagedir ${basedir}=basedir ${ptBinMin}ptBinMin ${ptBinMax}ptBinMax ${cpmBinMin}cpmBinMin ${cpmBinMax}cpmBinMax ${nState}nState statErrConsideration=${statErrConsideration}


done
done

