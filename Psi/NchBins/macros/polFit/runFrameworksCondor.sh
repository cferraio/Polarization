#!/bin/sh

#### This shell file will automatically do *all* of the work needed for all the systematics, provided
#### that the ToyMC files in interface have been properly updated. Separate ToyMC files are required
#### for tests done with and without background. To do all of the tests, flag them below, run with 
#### ngen=1 to get everything set up. Once all jobs are complete change to ngen=50 and run again.
#### Each different systematic has an associated shell file set with proper settings. No need to change.
#### After all jobs are complete, plot them with PlotToyMC.sh

source /cvmfs/cms.cern.ch/cmsset_default.sh
cd /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit #comment out for non-condor
eval `scramv1 runtime -sh` #comment out for non-condor

source /cvmfs/sft.cern.ch/lcg/app/releases/ROOT/5.34.05/x86_64-slc5-gcc43-opt/root/bin/thisroot.sh                                     
source /cvmfs/sft.cern.ch/lcg/app/releases/ROOT/5.34.05/x86_64-slc5-gcc43-opt/root/bin/setxrd.sh /cvmfs/sft.cern.ch/lcg/external/xrootd/3.2.4/x86_64-slc5-gcc46-opt/

JobIDname=ThirdResult_ForPreApproval

ngen=50
storagedir=/data/users/ferraioc/Polarization/JPsi/NchBins/
homedir=/home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit
cd ${homedir}
cd ..
cd ..
basedir=$PWD
cd macros/polFit
#rm ToyMClogs/*
storagedir=${storagedir}/ToyMC

doFrameworks=0
TnPModel=0
TnPParam=0
RhoFactor=0
VtxSyst=0

if [ $TnPParam -eq 1 ]
then
 for nState in 4 5; do
 echo "Starting TnPParam"
	 for param in 1061 1062 1063 1064 1065 1066
	 do
	  JobID=TnPParam${param}_Psi$[nState-3]_${JobIDname}
	  polScenSig=3
	  polScenBkg=3
	  frameSig=1
	  frameBkg=1
	  UseConstEv=true
	  ScenDir=Sig_frame${frameSig}scen${polScenSig}_Bkg_frame${frameBkg}scen${polScenBkg}
	  mkdir -p ${storagedir}/${JobID}/${ScenDir}
	  cd ${homedir}
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
	  cp ../../interface/ToyMC_Psi$[nState-3]S_fw2.h  ${storagedir}/${JobID}/${ScenDir}/ToyMC.h ##this has bg = 0.001
	  cp ../../interface/effsAndCuts_Psi$[nState-3]S.h ${storagedir}/${JobID}/${ScenDir}/effsAndCuts.h
	  cd ${storagedir}/${JobID}/${ScenDir}
	  touch polGenRecFitPlot.cc
	  make
	  cd ${homedir}
	  if [ $ngen -eq 1 ]
	  then
	  n=1
	  fi
	  if [ $ngen -gt 1 ]
	  then
	  n=2
	  fi
	  while [[ $n -le $ngen ]]
	  do
		if [ $nState -eq 4 ]
		then
		  for pt in 1 2
		  do
			for cpm in 1 2 3 4 5 6 7 8 9 10 11 12
			do
			  rm tnpparam.jdl
			  touch tnpparam.jdl
			  echo "universe = vanilla" >> tnpparam.jdl
			  echo "Executable = runTnPParam.sh" >> tnpparam.jdl
			  echo "getenv = True" >> tnpparam.jdl
			  echo "requirements = (OpSys == \"LINUX\")" >> tnpparam.jdl
			  echo "should_transfer_files = NO" >> tnpparam.jdl
			  echo "Requirements = TARGET.FileSystemDomain == \"privnet\"" >> tnpparam.jdl
			  echo "Output = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stdout" >> tnpparam.jdl
			  echo "Error  = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stderr" >> tnpparam.jdl
			  echo "Log    = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).condor" >> tnpparam.jdl
			  echo "Arguments = $pt $cpm $[n-1] $nState $JobID $param" >> tnpparam.jdl
			  echo "Queue 1" >> tnpparam.jdl
			  condor_submit tnpparam.jdl
			done
		  done
		fi
		
		
		if [ $nState -eq 5 ]
		then
		  for pt in 1 2
		  do
			for cpm in 1 2 3 4 5
			do
			  rm tnpparam.jdl
			  touch tnpparam.jdl
			  echo "universe = vanilla" >> tnpparam.jdl
			  echo "Executable = runTnPParam.sh" >> tnpparam.jdl
			  echo "getenv = True" >> tnpparam.jdl
			  echo "requirements = (OpSys == \"LINUX\")" >> tnpparam.jdl
			  echo "should_transfer_files = NO" >> tnpparam.jdl
			  echo "Requirements = TARGET.FileSystemDomain == \"privnet\"" >> tnpparam.jdl
			  echo "Output = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stdout" >> tnpparam.jdl
			  echo "Error  = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stderr" >> tnpparam.jdl
			  echo "Log    = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).condor" >> tnpparam.jdl
			  echo "Arguments = $pt $cpm $[n-1] $nState $JobID $param" >> tnpparam.jdl
			  echo "Queue 1" >> tnpparam.jdl
			  condor_submit tnpparam.jdl
			done
		  done
		fi
	  n=$(( n+1 ))
	  done
	 done
 done
fi

if [ $VtxSyst -eq 1 ]
then
 for nState in 4 5; do
 echo "Starting VtxSyst"
	  JobID=VtxSyst_Psi$[nState-3]_${JobIDname}
	  polScenSig=3
	  polScenBkg=3
	  frameSig=1
	  frameBkg=1
	  UseConstEv=true
	  ScenDir=Sig_frame${frameSig}scen${polScenSig}_Bkg_frame${frameBkg}scen${polScenBkg}
	  mkdir -p ${storagedir}/${JobID}/${ScenDir}
	  cd ${homedir}
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
	  cp ../../interface/ToyMC_Psi$[nState-3]S_fw2.h  ${storagedir}/${JobID}/${ScenDir}/ToyMC.h ##this has bg = 0.001
	  cp ../../interface/effsAndCuts_Psi$[nState-3]S.h ${storagedir}/${JobID}/${ScenDir}/effsAndCuts.h
	  cd ${storagedir}/${JobID}/${ScenDir}
	  touch polGenRecFitPlot.cc
	  make
	  cd ${homedir}
	  if [ $ngen -eq 1 ]
	  then
	  n=1
	  fi
	  if [ $ngen -gt 1 ]
	  then
	  n=2
	  fi
	  while [[ $n -le $ngen ]]
	  do
		if [ $nState -eq 4 ]
		then
		  for pt in 1 2
		  do
			for cpm in 1 2 3 4 5 6 7 8 9 10 11 12
			do
			  rm vtxsyst.jdl
			  touch vtxsyst.jdl
			  echo "universe = vanilla" >> vtxsyst.jdl
			  echo "Executable = runVtxEffSyst.sh" >> vtxsyst.jdl
			  echo "getenv = True" >> vtxsyst.jdl
			  echo "requirements = (OpSys == \"LINUX\")" >> vtxsyst.jdl
			  echo "should_transfer_files = NO" >> vtxsyst.jdl
			  echo "Requirements = TARGET.FileSystemDomain == \"privnet\"" >> vtxsyst.jdl
			  echo "Output = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stdout" >> vtxsyst.jdl
			  echo "Error  = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stderr" >> vtxsyst.jdl
			  echo "Log    = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).condor" >> vtxsyst.jdl
			  echo "Arguments = $pt $cpm $[n-1] $nState $JobID" >> vtxsyst.jdl
			  echo "Queue 1" >> vtxsyst.jdl
			  condor_submit vtxsyst.jdl
			done
		  done
		fi
		
		
		if [ $nState -eq 5 ]
		then
		  for pt in 1 2
		  do
			for cpm in 1 2 3 4 5
			do
			  rm vtxsyst.jdl
			  touch vtxsyst.jdl
			  echo "universe = vanilla" >> vtxsyst.jdl
			  echo "Executable = runVtxEffSyst.sh" >> vtxsyst.jdl
			  echo "getenv = True" >> vtxsyst.jdl
			  echo "requirements = (OpSys == \"LINUX\")" >> vtxsyst.jdl
			  echo "should_transfer_files = NO" >> vtxsyst.jdl
			  echo "Requirements = TARGET.FileSystemDomain == \"privnet\"" >> vtxsyst.jdl
			  echo "Output = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stdout" >> vtxsyst.jdl
			  echo "Error  = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stderr" >> vtxsyst.jdl
			  echo "Log    = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).condor" >> vtxsyst.jdl
			  echo "Arguments = $pt $cpm $[n-1] $nState $JobID" >> vtxsyst.jdl
			  echo "Queue 1" >> vtxsyst.jdl
			  condor_submit vtxsyst.jdl
			done
		  done
		fi
	  n=$(( n+1 ))
	  done
	
 done
fi


if [ $RhoFactor -eq 1 ]
then
 for nState in 4 5; do
  echo "Starting RhoFactor"
	  JobID=RhoFactor_Psi$[nState-3]_${JobIDname}
	  polScenSig=3
	  polScenBkg=3
	  frameSig=1
	  frameBkg=1
	  UseConstEv=true
	  ScenDir=Sig_frame${frameSig}scen${polScenSig}_Bkg_frame${frameBkg}scen${polScenBkg}
	  mkdir -p ${storagedir}/${JobID}/${ScenDir}
	  cd ${homedir}
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
	  cp ../../interface/ToyMC_Psi$[nState-3]S_fw2.h  ${storagedir}/${JobID}/${ScenDir}/ToyMC.h ##this has bg = 0.001
	  cp ../../interface/effsAndCuts_Psi$[nState-3]S.h ${storagedir}/${JobID}/${ScenDir}/effsAndCuts.h
	  cd ${storagedir}/${JobID}/${ScenDir}
	  touch polGenRecFitPlot.cc
	  make
	  cd ${homedir}
	  if [ $ngen -eq 1 ]
	  then
	  n=1
	  fi
	  if [ $ngen -gt 1 ]
	  then
	  n=2
	  fi
	  while [[ $n -le $ngen ]]
	  do
		if [ $nState -eq 4 ]
		then
		  for pt in 1 2
		  do
			for cpm in 1 2 3 4 5 6 7 8 9 10 11 12
			do
			  rm rhofactor.jdl
			  touch rhofactor.jdl
			  echo "universe = vanilla" >> rhofactor.jdl
			  echo "Executable = runRhoFactorToys.sh" >> rhofactor.jdl
			  echo "getenv = True" >> rhofactor.jdl
			  echo "requirements = (OpSys == \"LINUX\")" >> rhofactor.jdl
			  echo "should_transfer_files = NO" >> rhofactor.jdl
			  echo "Requirements = TARGET.FileSystemDomain == \"privnet\"" >> rhofactor.jdl
			  echo "Output = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stdout" >> rhofactor.jdl
			  echo "Error  = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stderr" >> rhofactor.jdl
			  echo "Log    = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).condor" >> rhofactor.jdl
			  echo "Arguments = $pt $cpm $[n-1] $nState $JobID" >> rhofactor.jdl
			  echo "Queue 1" >> rhofactor.jdl
			  condor_submit rhofactor.jdl
			done
		  done
		fi
		
		
		if [ $nState -eq 5 ]
		then
		  for pt in 1 2
		  do
			for cpm in 1 2 3 4 5
			do
			  rm rhofactor.jdl
			  touch rhofactor.jdl
			  echo "universe = vanilla" >> rhofactor.jdl
			  echo "Executable = runRhoFactorToys.sh" >> rhofactor.jdl
			  echo "getenv = True" >> rhofactor.jdl
			  echo "requirements = (OpSys == \"LINUX\")" >> rhofactor.jdl
			  echo "should_transfer_files = NO" >> rhofactor.jdl
			  echo "Requirements = TARGET.FileSystemDomain == \"privnet\"" >> rhofactor.jdl
			  echo "Output = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stdout" >> rhofactor.jdl
			  echo "Error  = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stderr" >> rhofactor.jdl
			  echo "Log    = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).condor" >> rhofactor.jdl
			  echo "Arguments = $pt $cpm $[n-1] $nState $JobID" >> rhofactor.jdl
			  echo "Queue 1" >> rhofactor.jdl
			  condor_submit rhofactor.jdl
			done
		  done
		fi
	  n=$(( n+1 ))
	  done
	
 done
fi



if [ $TnPModel -eq 1 ]
then
 for nState in 4 5; do
  	  echo "Starting TnPModel"
	  JobID=TnPModel_Psi$[nState-3]_${JobIDname}
	  polScenSig=3
	  polScenBkg=3
	  frameSig=1
	  frameBkg=1
	  UseConstEv=true
	  ScenDir=Sig_frame${frameSig}scen${polScenSig}_Bkg_frame${frameBkg}scen${polScenBkg}
	  mkdir -p ${storagedir}/${JobID}/${ScenDir}
	  cd ${homedir}
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
	  cp ../../interface/ToyMC_Psi$[nState-3]S_fw2.h  ${storagedir}/${JobID}/${ScenDir}/ToyMC.h ##this has bg = 0.001
	  cp ../../interface/effsAndCuts_Psi$[nState-3]S.h ${storagedir}/${JobID}/${ScenDir}/effsAndCuts.h
	  cd ${storagedir}/${JobID}/${ScenDir}
	  touch polGenRecFitPlot.cc
	  make
	  cd ${homedir}
	  if [ $ngen -eq 1 ]
	  then
	  n=1
	  fi
	  if [ $ngen -gt 1 ]
	  then
	  n=2
	  fi
	  while [[ $n -le $ngen ]]
	  do
		if [ $nState -eq 4 ]
		then
		  for pt in 1 2
		  do
			for cpm in 1 2 3 4 5 6 7 8 9 10 11 12
			do
			  rm tnpmodel.jdl
			  touch tnpmodel.jdl
			  echo "universe = vanilla" >> tnpmodel.jdl
			  echo "Executable = runTnPModelToys.sh" >> tnpmodel.jdl
			  echo "getenv = True" >> tnpmodel.jdl
			  echo "requirements = (OpSys == \"LINUX\")" >> tnpmodel.jdl
			  echo "should_transfer_files = NO" >> tnpmodel.jdl
			  echo "Requirements = TARGET.FileSystemDomain == \"privnet\"" >> tnpmodel.jdl
			  echo "Output = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stdout" >> tnpmodel.jdl
			  echo "Error  = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stderr" >> tnpmodel.jdl
			  echo "Log    = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).condor" >> tnpmodel.jdl
			  echo "Arguments = $pt $cpm $[n-1] $nState $JobID" >> tnpmodel.jdl
			  echo "Queue 1" >> tnpmodel.jdl
			  condor_submit tnpmodel.jdl
			done
		  done
		fi
		
		
		if [ $nState -eq 5 ]
		then
		  for pt in 1 2
		  do
			for cpm in 1 2 3 4 5
			do
			  rm tnpmodel.jdl
			  touch tnpmodel.jdl
			  echo "universe = vanilla" >> tnpmodel.jdl
			  echo "Executable = runTnPModelToys.sh" >> tnpmodel.jdl
			  echo "getenv = True" >> tnpmodel.jdl
			  echo "requirements = (OpSys == \"LINUX\")" >> tnpmodel.jdl
			  echo "should_transfer_files = NO" >> tnpmodel.jdl
			  echo "Requirements = TARGET.FileSystemDomain == \"privnet\"" >> tnpmodel.jdl
			  echo "Output = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stdout" >> tnpmodel.jdl
			  echo "Error  = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stderr" >> tnpmodel.jdl
			  echo "Log    = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).condor" >> tnpmodel.jdl
			  echo "Arguments = $pt $cpm $[n-1] $nState $JobID" >> tnpmodel.jdl
			  echo "Queue 1" >> tnpmodel.jdl
			  condor_submit tnpmodel.jdl
			done
		  done
		fi
	  n=$(( n+1 ))
	  done
 done
fi

if [ $doFrameworks -eq 1 ]
then
 for Framework in 1 2 3;do
  for nState in 4 5; do
   if [ $Framework -eq 1 ]
   then
	 echo "Starting Framework $Framework"
	 JobID=FrameworkI_Psi$[nState-3]_${JobIDname}
	 polScenSig=3
	 polScenBkg=3
	 frameSig=1
	 frameBkg=1
	 UseConstEv=false
	 ScenDir=Sig_frame${frameSig}scen${polScenSig}_Bkg_frame${frameBkg}scen${polScenBkg}
	 mkdir -p ${storagedir}/${JobID}/${ScenDir}
	 cd ${homedir}
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
	 cd ${storagedir}/${JobID}/${ScenDir}
	 touch polGenRecFitPlot.cc
	 make
	 cd ${homedir}
	 if [ $ngen -eq 1 ]
	 then
	 n=1
	 fi
	 if [ $ngen -gt 1 ]
	 then
	 n=2
	 fi
	 while [[ $n -le $ngen ]]
	 do
	   if [ $nState -eq 4 ]
	   then
		   for cpm in 1 2 3 4 5 6 7 8 9 10 11 12
		   do
			  rm framework.jdl
			  touch framework.jdl
			  echo "universe = vanilla" >> framework.jdl
			  echo "Executable = runFrameworks.sh" >> framework.jdl
			  echo "getenv = True" >> framework.jdl
			  echo "requirements = (OpSys == \"LINUX\")" >> framework.jdl
			  echo "should_transfer_files = NO" >> framework.jdl
			  echo "Requirements = TARGET.FileSystemDomain == \"privnet\"" >> framework.jdl
			  echo "Output = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stdout" >> framework.jdl
			  echo "Error  = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stderr" >> framework.jdl
			  echo "Log    = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).condor" >> framework.jdl
			 echo "Arguments = $cpm $[n-1] $polScenSig $polScenBkg $frameSig $frameBkg $UseConstEv $nState $JobID" >> framework.jdl
			 echo "Queue 1" >> framework.jdl
			 condor_submit framework.jdl
		   done
	   fi
	   if [ $nState -eq 5 ]
	   then
		   for cpm in 1 2 3 4 5
		   do
			  rm framework.jdl
			  touch framework.jdl
			  echo "universe = vanilla" >> framework.jdl
			  echo "Executable = runFrameworks.sh" >> framework.jdl
			  echo "getenv = True" >> framework.jdl
			  echo "requirements = (OpSys == \"LINUX\")" >> framework.jdl
			  echo "should_transfer_files = NO" >> framework.jdl
			  echo "Requirements = TARGET.FileSystemDomain == \"privnet\"" >> framework.jdl
			  echo "Output = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stdout" >> framework.jdl
			  echo "Error  = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stderr" >> framework.jdl
			  echo "Log    = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).condor" >> framework.jdl
			 echo "Arguments = $cpm $[n-1] $polScenSig $polScenBkg $frameSig $frameBkg $UseConstEv $nState $JobID" >> framework.jdl
			 echo "Queue 1" >> framework.jdl
			 condor_submit framework.jdl
		   done
	   fi
	 n=$(( n+1 ))
	 done
   fi

   if [ $Framework -eq 2 ]
   then
	 echo "Starting Framework $Framework"
	 JobID=FrameworkII_Psi$[nState-3]_${JobIDname}
	 frameSig=3
	 frameBkg=3
	 polScenBkg=1
	 UseConstEv=true
	 for polScenSig in 1 2 4 5
	 do
	   ScenDir=Sig_frame${frameSig}scen${polScenSig}_Bkg_frame${frameBkg}scen${polScenBkg}
	   mkdir -p ${storagedir}/${JobID}/${ScenDir}
	   cd ${homedir}
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
	   cp ../../interface/ToyMC_Psi$[nState-3]S_fw2.h ${storagedir}/${JobID}/${ScenDir}/ToyMC.h
	   cp ../../interface/effsAndCuts_Psi$[nState-3]S.h ${storagedir}/${JobID}/${ScenDir}/effsAndCuts.h
	   cd ${storagedir}/${JobID}/${ScenDir}
	   touch polGenRecFitPlot.cc
	   make
	   cd ${homedir}
	   if [ $ngen -eq 1 ]
	 then
	 n=1
	 fi
	 if [ $ngen -gt 1 ]
	 then
	 n=2
	 fi
	   while [[ $n -le $ngen ]]
	   do
		 if [ $nState -eq 4 ]
		 then
			 for cpm in 1 2 3 4 5 6 7 8 9 10 11 12
			 do
			   rm framework.jdl
			  touch framework.jdl
			  echo "universe = vanilla" >> framework.jdl
			  echo "Executable = runFrameworks.sh" >> framework.jdl
			  echo "getenv = True" >> framework.jdl
			  echo "requirements = (OpSys == \"LINUX\")" >> framework.jdl
			  echo "should_transfer_files = NO" >> framework.jdl
			  echo "Requirements = TARGET.FileSystemDomain == \"privnet\"" >> framework.jdl
			  echo "Output = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stdout" >> framework.jdl
			  echo "Error  = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stderr" >> framework.jdl
			  echo "Log    = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).condor" >> framework.jdl
			 echo "Arguments = $cpm $[n-1] $polScenSig $polScenBkg $frameSig $frameBkg $UseConstEv $nState $JobID" >> framework.jdl
			 echo "Queue 1" >> framework.jdl
			 condor_submit framework.jdl
			 done
		 fi
		 
		 if [ $nState -eq 5 ]
		 then
			 for cpm in 1 2 3 4 5
			 do
			   rm framework.jdl
			  touch framework.jdl
			  echo "universe = vanilla" >> framework.jdl
			  echo "Executable = runFrameworks.sh" >> framework.jdl
			  echo "getenv = True" >> framework.jdl
			  echo "requirements = (OpSys == \"LINUX\")" >> framework.jdl
			  echo "should_transfer_files = NO" >> framework.jdl
			  echo "Requirements = TARGET.FileSystemDomain == \"privnet\"" >> framework.jdl
			  echo "Output = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stdout" >> framework.jdl
			  echo "Error  = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stderr" >> framework.jdl
			  echo "Log    = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).condor" >> framework.jdl
			 echo "Arguments = $cpm $[n-1] $polScenSig $polScenBkg $frameSig $frameBkg $UseConstEv $nState $JobID" >> framework.jdl
			 echo "Queue 1" >> framework.jdl
			 condor_submit framework.jdl
			 done
		 fi
	   n=$(( n+1 ))
	   done
	 done  
   fi
 
   if [ $Framework -eq 3 ]
   then
	 echo "Starting Framework $Framework"
	 JobID=FrameworkIII_Psi$[nState-3]_${JobIDname}
	 polScenSig=3
	 polScenBkg=4
	 frameSig=1
	 frameBkg=1
	 UseConstEv=true
	 ScenDir=Sig_frame${frameSig}scen${polScenSig}_Bkg_frame${frameBkg}scen${polScenBkg}
	 mkdir -p ${storagedir}/${JobID}/${ScenDir}
	 cd ${homedir}
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
	 cd ${storagedir}/${JobID}/${ScenDir}
	 touch polGenRecFitPlot.cc
	 make
	 cd ${homedir}
	 if [ $ngen -eq 1 ]
	 then
	 n=1
	 fi
	 if [ $ngen -gt 1 ]
	 then
	 n=2
	 fi
	 while [[ $n -le $ngen ]]
	 do
	   if [ $nState -eq 4 ]
	   then
		   for cpm in 1 2 3 4 5 6 7 8 9 10 11 12
		   do
			 rm framework.jdl
			  touch framework.jdl
			  echo "universe = vanilla" >> framework.jdl
			  echo "Executable = runFrameworks.sh" >> framework.jdl
			  echo "getenv = True" >> framework.jdl
			  echo "requirements = (OpSys == \"LINUX\")" >> framework.jdl
			  echo "should_transfer_files = NO" >> framework.jdl
			  echo "Requirements = TARGET.FileSystemDomain == \"privnet\"" >> framework.jdl
			  echo "Output = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stdout" >> framework.jdl
			  echo "Error  = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stderr" >> framework.jdl
			  echo "Log    = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).condor" >> framework.jdl
			 echo "Arguments = $cpm $[n-1] $polScenSig $polScenBkg $frameSig $frameBkg $UseConstEv $nState $JobID" >> framework.jdl
			 echo "Queue 1" >> framework.jdl
			 condor_submit framework.jdl
		   done
	   fi
	   
	   
	   if [ $nState -eq 5 ]
	   then
		   for cpm in 1 2 3 4 5
		   do
			 rm framework.jdl
			  touch framework.jdl
			  echo "universe = vanilla" >> framework.jdl
			  echo "Executable = runFrameworks.sh" >> framework.jdl
			  echo "getenv = True" >> framework.jdl
			  echo "requirements = (OpSys == \"LINUX\")" >> framework.jdl
			  echo "should_transfer_files = NO" >> framework.jdl
			  echo "Requirements = TARGET.FileSystemDomain == \"privnet\"" >> framework.jdl
			  echo "Output = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stdout" >> framework.jdl
			  echo "Error  = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).stderr" >> framework.jdl
			  echo "Log    = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/polFit/ToyMClogs/simple_\$(cluster)_\$(process).condor" >> framework.jdl
			 echo "Arguments = $cpm $[n-1] $polScenSig $polScenBkg $frameSig $frameBkg $UseConstEv $nState $JobID" >> framework.jdl
			 echo "Queue 1" >> framework.jdl
			 condor_submit framework.jdl
		   done
	   fi
	 n=$(( n+1 ))
	 done
   fi
 
  done
 done
fi