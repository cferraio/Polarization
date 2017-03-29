#!/bin/sh

homedir=`pwd`
cd ..
cd ..
basedir=`pwd`
cd macros/polFit
storagedir=`more storagedir`/Data #please define the directory storagedir in the file macros/polFit/storagedir

########## INPUTS ##########

for nState in 3;do



SystID=cutNPriVtx_smallerpT2_FinalSyst

nSystematics=3


JobID1=Nch_FrameworkI
JobID2=Nch_FrameworkII
JobID3=Nch_FrameworkIII
#JobID1=cutNPriVtx_smallerpT2_Parametrization/ChangedTGraph
#JobID2=cutNPriVtx_smallerpT2_RhoFactor/ChangedTGraph
#JobID3=cutNPriVtx_smallerpT2_TnP_model/ChangedTGraph
#JobID6=BGsyst/cutNPriVtx_smallerpT2_fLSB59_TO_cutNPriVtx_smallerpT2_fLSB2

#JobID7=withsys/cutNPriVtx_smallerpT2_FracL100_TO_cutNPriVtx_smallerpT2_FracL44
#JobID7=cutNPriVtx_smallerpT2BGSyst/cutNPriVtx_smallerpT2_FracL74_TO_cutNPriVtx_smallerpT2_FracL18
#JobID7=cutNPriVtx_smallerpT2BGSyst/cutNPriVtx_smallerpT2_fracL59_TO_cutNPriVtx_smallerpT2_fracL2
#JobID7=cutNPriVtx_smallerpT2BGSyst/cutNPriVtx_smallerpT2_fracL59_TO_cutNPriVtx_smallerpT2_fracL2


#JobID1=cutNPriVtx_smallerpT2_4CPMBins_FrameworkI
#JobID2=cutNPriVtx_smallerpT2_4CPMBins_FrameworkII
#JobID3=cutNPriVtx_smallerpT2_4CPMBins_FrameworkIII
#JobID4=cutNPriVtx_smallerpT2_4CPMBins_Parametrization
#JobID5=cutNPriVtx_smallerpT2_4CPMBins_RhoFactor
#JobID6=cutNPriVtx_smallerpT2_4CPMBins_TnP_model
#JobID7=cutNPriVtx_smallerpT2BGSyst/cutNPriVtx_smallerpT2_FracL100_TO_cutNPriVtx_smallerpT2_FracL44
#JobID7=cutNPriVtx_smallerpT2BGSyst/cutNPriVtx_smallerpT2_FracL74_TO_cutNPriVtx_smallerpT2_FracL18
#JobID7=cutNPriVtx_smallerpT2BGSyst/cutNPriVtx_smallerpT2_fracL59_TO_cutNPriVtx_smallerpT2_fracL2
#JobID7=cutNPriVtx_smallerpT2BGSyst/cutNPriVtx_smallerpT2_fracL59_TO_cutNPriVtx_smallerpT2_fracL2
#JobID7=cutNPriVtx_smallerpT2BGSyst_4CPMBins/cutNPriVtx_smallerpT2_4CPMBins_fracL59_TO_cutNPriVtx_smallerpT2_4CPMBins_fracL2
JobID8=
JobID9=


cpmBinMin=1
cpmBinMax=5

ptBinMin=2
ptBinMax=2

########################################

cd ${homedir}

touch AverageSystematics.cc
make

mkdir Systematics
mkdir Systematics/${SystID}

SystDir=Systematics/${SystID}/AverageSyst

mkdir ${SystDir}


./AverageSystematics ${JobID1}=JobID1 ${JobID2}=JobID2 ${JobID3}=JobID3 ${JobID4}=JobID4 ${JobID5}=JobID5 ${JobID6}=JobID6 ${JobID7}=JobID7 ${JobID8}=JobID8 ${JobID9}=JobID9 ${SystID}=SystID ${storagedir}=storagedir ${basedir}=basedir ${cpmBinMin}cpmBinMin ${cpmBinMax}cpmBinMax ${ptBinMin}ptBinMin ${ptBinMax}ptBinMax ${nState}nState ${nSystematics}nSystematics


done


