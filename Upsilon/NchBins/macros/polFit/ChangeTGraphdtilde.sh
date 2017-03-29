#!/bin/sh

homedir=`pwd`
cd ..
cd ..
basedir=`pwd`
cd macros/polFit
storagedir=`more storagedir`/Data #please define the directory storagedir in the file macros/polFit/storagedir

########## INPUTS ##########

for nState in 1;do

SystID=Dtilde
JobID=/data/users/ferraioc/Polarization/Modified/Data/GreatCPMRun2_withsys/TGraphResults_1SUps.root

ptBinMin=1
ptBinMax=2

cpmBinMin=1
cpmBinMax=5

########################################

cd ${homedir}

touch ChangeTGraphdtilde.cc
make

mkdir Systematics
mkdir Systematics/${SystID}

SystDir=Systematics/${SystID}/ChangedTGraph

mkdir ${SystDir}


./ChangeTGraphdtilde ${JobID}=JobID1 ${SystID}=SystID ${storagedir}=storagedir ${basedir}=basedir ${ptBinMin}ptBinMin ${ptBinMax}ptBinMax ${cpmBinMin}cpmBinMin ${cpmBinMax}cpmBinMax ${nState}nState


done


