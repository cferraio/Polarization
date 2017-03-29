#!/bin/sh

homedir=`pwd`
cd ..
cd ..
basedir=`pwd`
cd macros/polFit
storagedir=`more storagedir`/Data #please define the directory storagedir in the file macros/polFit/storagedir

########## INPUTS ##########

for nState in 3;do

SystID=cutNPriVtx_at10
JobID=/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/BiasCorrection_1S2S3SAug12_1Sig
#SystID=cutNPriVtx_FrameworkI_smallerpT2
#JobID=/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/FrameworkI
#SystID=cutNPriVtx_FrameworkII_smallerpT2
#JobID=/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/FrameworkII
#SystID=cutNPriVtx_FrameworkIII_smallerpT2
#JobID=/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/FrameworkIII
#SystID=cutNPriVtx_Parametrization_smallerpT2
#JobID=/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/Parametrization
#SystID=cutNPriVtx_RhoFactor_smallerpT2
#JobID=/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/RhoFactor
#SystID=cutNPriVtx_TnP_model_smallerpT2
#JobID=/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/TnP_model
#SystID=deltatilde
#JobID=/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx_withsys

ptBinMin=1
ptBinMax=1

cpmBinMin=1
cpmBinMax=4

########################################

cd ${homedir}

touch ChangeTGraph.cc
make

mkdir Systematics
mkdir Systematics/${SystID}

SystDir=Systematics/${SystID}/ChangedTGraph

mkdir ${SystDir}


./ChangeTGraph ${JobID}=JobID1 ${SystID}=SystID ${storagedir}=storagedir ${basedir}=basedir ${ptBinMin}ptBinMin ${ptBinMax}ptBinMax ${cpmBinMin}cpmBinMin ${cpmBinMax}cpmBinMax ${nState}nState


done


