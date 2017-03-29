#!/bin/sh

homedir=`pwd`
cd ..
cd ..
basedir=`pwd`
cd macros/polFit
storagedir=`more storagedir`/Data #please define the directory storagedir in the file macros/polFit/storagedir

########## INPUTS ##########

for nState in 3;do

JobID=cutNPriVtx_smallerpT2_FinalSyst_Glob

DefaultID=cutNPriVtx_smallerpT2
#DefaultID=Reanalysis_4cpmbins
#DefaultID=Ups2S_fracL46_nSima3
#DefaultID=Ups2S_fracL46_nSima3
#DefaultID=Ups1S_fracL72_nSima3
#ShiftID=zeros
ShiftID=cutNPriVtx_smallerpT2_BiasCorrection #need to get this, make Tgraph filled with 0s if you want to run without
#ShiftID=zeros
ShiftResults=1

nSystematics=2

#ProbDist 1...gauss, 2...linear
#SystID2Base=cutNPriVtx
#SystID2Specify=AverageSyst
#SystID2Title=TotalSyst_ExceptBKGmodel
#SystID2ProbDist=1 #only linear for the background, the rest are gaussian

 SystID1Base=cutNPriVtx_smallerpT2_FinalSyst
 SystID1Specify=cutNPriVtx_smallerpT2_BGE/cutNPriVtx_smallerpT2_bgeH_TO_cutNPriVtx_smallerpT2_bgeL 
 SystID1Title=BKGmodel
 SystID1ProbDist=2
# 
SystID2Base=cutNPriVtx_smallerpT2_FinalSyst
SystID2Specify=AverageSyst
SystID2Title=Average
SystID2ProbDist=1
# 
#  SystID1Base=cutNPriVtx_FrameworkII_4cpmbins
#  SystID1Specify=ChangedTGraph
#  SystID1Title=FrameworkII
#  SystID1ProbDist=1
# # 
#  SystID4Base=cutNPriVtx_smallerpT2_FinalSyst
#  SystID4Specify=Nch_FrameworkIII
#  SystID4Title=FrameworkIII
#  SystID4ProbDist=1
# # 
#  SystID5Base=cutNPriVtx_smallerpT2_FinalSyst
#  SystID5Specify=cutNPriVtx_smallerpT2_Parametrization/ChangedTGraph
#  SystID5Title=Parametrization
#  SystID5ProbDist=1
# # 
#  SystID6Base=cutNPriVtx_smallerpT2_FinalSyst
#  SystID6Specify=cutNPriVtx_smallerpT2_RhoFactor/ChangedTGraph
#  SystID6Title=ThoFactor
#  SystID6ProbDist=1
# # 
#  SystID7Base=cutNPriVtx_smallerpT2_FinalSyst
#  SystID7Specify=cutNPriVtx_smallerpT2_TnP_model/ChangedTGraph
#  SystID7Title=TnP_model
#  SystID7ProbDist=1


cpmBinMin=5
cpmBinMax=5

ptBinMin=2
ptBinMax=2

rapBinMin=1
rapBinMax=1


########################################

cd ${homedir}

touch AlterPPD.cc
make


JobIDDir=${storagedir}/${DefaultID}
JobIDDirAlterPPD=${storagedir}/${DefaultID}_${JobID}

mkdir ${JobIDDirAlterPPD}

rap_=${rapBinMin}
while [ $rap_ -le ${rapBinMax} ]
do
pT_=${ptBinMin}
while [ $pT_ -le ${ptBinMax} ]
do
cpm_=${cpmBinMin}
while [ $cpm_ -le ${cpmBinMax} ]
do

rm ${JobIDDirAlterPPD}/results_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.root
cp ${JobIDDir}/results_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.root ${JobIDDirAlterPPD}/results_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.root

./AlterPPD ${DefaultID}=DefaultID ${ShiftID}=ShiftID ${JobID}=JobID ${SystID1Base}=SystID1Base ${SystID1Specify}=SystID1Specify ${SystID1Title}=SystID1Title ${SystID2Base}=SystID2Base ${SystID2Specify}=SystID2Specify ${SystID2Title}=SystID2Title ${SystID3Base}=SystID3Base ${SystID3Specify}=SystID3Specify ${SystID3Title}=SystID3Title ${SystID4Base}=SystID4Base ${SystID4Specify}=SystID4Specify ${SystID4Title}=SystID4Title ${SystID5Base}=SystID5Base ${SystID5Specify}=SystID5Specify ${SystID5Title}=SystID5Title ${SystID6Base}=SystID6Base ${SystID6Specify}=SystID6Specify ${SystID6Title}=SystID6Title ${SystID7Base}=SystID7Base ${SystID7Specify}=SystID7Specify ${SystID7Title}=SystID7Title ${SystID8Base}=SystID8Base ${SystID8Specify}=SystID8Specify ${SystID8Title}=SystID8Title ${SystID1ProbDist}SystID1ProbDist ${SystID2ProbDist}SystID2ProbDist ${SystID3ProbDist}SystID3ProbDist ${SystID4ProbDist}SystID4ProbDist ${SystID5ProbDist}SystID5ProbDist ${SystID6ProbDist}SystID6ProbDist ${SystID7ProbDist}SystID7ProbDist ${SystID8ProbDist}SystID8ProbDist ${basedir}=basedir ${storagedir}=storagedir ${cpm_}cpmBinMin ${cpm_}cpmBinMax ${pT_}ptBinMin ${pT_}ptBinMax ${rap_}rapBinMin ${rap_}rapBinMax ${nSystematics}nSystematics ${nState}nState ShiftResults=${ShiftResults} 

cpm_=$((cpm_+1))
done

pT_=$((pT_+1))
done
rap_=$((rap_+1))
done

done
