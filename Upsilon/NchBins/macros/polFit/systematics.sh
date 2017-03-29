#!/bin/sh

homedir=`pwd`
cd ..
cd ..
basedir=`pwd`
cd macros/polFit
storagedir=`more storagedir`/Data #please define the directory storagedir in the file macros/polFit/storagedir

########## INPUTS ##########

for nState in 1 2 3;do

SystID=systematicssystid

JobID=systematicsjobid

ptBinMin=1
ptBinMax=2
cpmBinMin=1
cpmBinMax=5

########################################

cd ${homedir}

touch systematics.cc
make

mkdir Systematics
mkdir Systematics/${SystID}

SystDir=Systematics/${SystID}/systematics

mkdir ${SystDir}


./systematics ${JobID}=JobID1 ${SystID}=SystID ${storagedir}=storagedir ${basedir}=basedir ${ptBinMin}ptBinMin ${ptBinMax}ptBinMax ${cpmBinMin}cpmBinMin ${cpmBinMax}cpmBinMax ${nState}nState


done


