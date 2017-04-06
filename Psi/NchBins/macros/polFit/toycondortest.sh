#!/bin/sh

JobIDname=SecondResult_npriVtxCut

CONDOR_JOB="runtoyscondor.jdl"

ngen=50

x=0
#for Framework in 1 2 3;do
for Framework in 2;do
  for nState in 4 5; do
    if [ $Framework -eq 1 ]
	then
	  JobID=FrameworkI_Psi$[nState-3]_${JobIDname}
	  polScenSig=3
	  polScenBkg=3
	  frameSig=1
	  frameBkg=1
	  UseConstEv=false
	  ScenDir=Sig_frame${frameSig}scen${polScenSig}_Bkg_frame${frameBkg}scen${polScenBkg}
	  n=1
	  while [[ $n -le $ngen ]]
	  do
		if [ $nState -eq 4 ]
		then
		 for pt in 1 2;do
		  for cpm in 1 2 3 4 5 6 7 8 9 10 11 12
		  do
		    FILE=/data/users/ferraioc/Polarization/JPsi/NchBins/ToyMC/$JobID/$ScenDir/rap1_pT${pt}_cpm${cpm}/Generation${n}/results.root 
		   # echo $FILE
		    if [ ! -f "$FILE" ];
			then
			   echo "File $FILE does not exist" 
			   cp runcondorToys.jdl runtoyscondor.jdl
			   redo=$[gen_-1]
			   echo "$cpm $[n-1] $polScenSig $polScenBkg $frameSig $frameBkg $UseConstEv $nState $JobID" >> runtoyscondor.jdl
			   echo "Queue 1" >> runtoyscondor.jdl
			   sleep 1
			   condor_submit runtoyscondor.jdl
			   x=$[x+1]
			fi
		  done
		 done
		fi
		if [ $nState -eq 5 ]
		then
		 for pt in 1 2;do
		  for cpm in 1 2 3 4 5 
		  do
		    FILE=/data/users/ferraioc/Polarization/JPsi/NchBins/ToyMC/$JobID/$ScenDir/rap1_pT${pt}_cpm${cpm}/Generation${n}/results.root 
		    if [ ! -f "$FILE" ];
			then
			   echo "File $FILE does not exist" 
			   cp runcondorToys.jdl runtoyscondor.jdl
			   redo=$[gen_-1]
			   echo "$cpm $[n-1] $polScenSig $polScenBkg $frameSig $frameBkg $UseConstEv $nState $JobID" >> runtoyscondor.jdl
			   echo "Queue 1" >> runtoyscondor.jdl
			   sleep 1
			   condor_submit runtoyscondor.jdl
			   x=$[x+1]
			fi
		  done
		 done
		fi
	  n=$(( n+1 ))
	  done
	fi
	if [ $Framework -eq 2 ]
	then
	  JobID=FrameworkII_Psi$[nState-3]_${JobIDname}
	  frameSig=3
	  frameBkg=3
	  polScenBkg=1
	  UseConstEv=true
	  for polScenSig in 1 2 4 5
	  do
	  ScenDir=Sig_frame${frameSig}scen${polScenSig}_Bkg_frame${frameBkg}scen${polScenBkg}
	  n=1
	  while [[ $n -le $ngen ]]
	  do
		if [ $nState -eq 4 ]
		then
		 for pt in 1 2;do
		  for cpm in 1 2 3 4 5 6 7 8 9 10 11 12
		  do
		    FILE=/data/users/ferraioc/Polarization/JPsi/NchBins/ToyMC/$JobID/$ScenDir/rap1_pT${pt}_cpm${cpm}/Generation${n}/results.root 
		    if [ ! -f "$FILE" ];
			then
			   echo "File $FILE does not exist" 
			   cp runcondorToys.jdl runtoyscondor.jdl
			   redo=$[gen_-1]
			   echo "$cpm $[n-1] $polScenSig $polScenBkg $frameSig $frameBkg $UseConstEv $nState $JobID" >> runtoyscondor.jdl
			   echo "Queue 1" >> runtoyscondor.jdl
			 #  sleep 1
			 #  condor_submit runtoyscondor.jdl
			   x=$[x+1]
			fi
		  done
		 done
		fi
		if [ $nState -eq 5 ]
		then
		 for pt in 1 2;do
		  for cpm in 1 2 3 4 5 
		  do
		    FILE=/data/users/ferraioc/Polarization/JPsi/NchBins/ToyMC/$JobID/$ScenDir/rap1_pT${pt}_cpm${cpm}/Generation${n}/results.root 
		    if [ ! -f "$FILE" ];
			then
			   echo "File $FILE does not exist" 
			   cp runcondorToys.jdl runtoyscondor.jdl
			   redo=$[gen_-1]
			   echo "$cpm $[n-1] $polScenSig $polScenBkg $frameSig $frameBkg $UseConstEv $nState $JobID" >> runtoyscondor.jdl
			   echo "Queue 1" >> runtoyscondor.jdl
			  # sleep 1
			  # condor_submit runtoyscondor.jdl
			   x=$[x+1]
			fi
		  done
		 done
		fi
	  n=$(( n+1 ))
	  done
	  done
	fi
	if [ $Framework -eq 3 ]
	then
	  JobID=FrameworkIII_Psi$[nState-3]_${JobIDname}
	  polScenSig=3
	  polScenBkg=4
	  frameSig=1
	  frameBkg=1
	  UseConstEv=true
	  ScenDir=Sig_frame${frameSig}scen${polScenSig}_Bkg_frame${frameBkg}scen${polScenBkg}
	  n=1
	  while [[ $n -le $ngen ]]
	  do
		if [ $nState -eq 4 ]
		then
		 for pt in 1 2;do
		  for cpm in 1 2 3 4 5 6 7 8 9 10 11 12
		  do
		    FILE=/data/users/ferraioc/Polarization/JPsi/NchBins/ToyMC/$JobID/$ScenDir/rap1_pT${pt}_cpm${cpm}/Generation${n}/results.root 
		    if [ ! -f "$FILE" ];
			then
			   echo "File $FILE does not exist" 
			   cp runcondorToys.jdl runtoyscondor.jdl
			   redo=$[gen_-1]
			   echo "$cpm $[n-1] $polScenSig $polScenBkg $frameSig $frameBkg $UseConstEv $nState $JobID" >> runtoyscondor.jdl
			   echo "Queue 1" >> runtoyscondor.jdl
			   sleep 1
			   condor_submit runtoyscondor.jdl
			   x=$[x+1]
			fi
		   done
		  done
		fi
		if [ $nState -eq 5 ]
		then
		 for pt in 1 2;do
		  for cpm in 1 2 3 4 5 
		  do
		    FILE=/data/users/ferraioc/Polarization/JPsi/NchBins/ToyMC/$JobID/$ScenDir/rap1_pT${pt}_cpm${cpm}/Generation${n}/results.root 
		    if [ ! -f "$FILE" ];
			then
			   echo "File $FILE does not exist" 
			   cp runcondorToys.jdl runtoyscondor.jdl
			   redo=$[gen_-1]
			   echo "$cpm $[n-1] $polScenSig $polScenBkg $frameSig $frameBkg $UseConstEv $nState $JobID" >> runtoyscondor.jdl
			   echo "Queue 1" >> runtoyscondor.jdl
			   sleep 1
			   condor_submit runtoyscondor.jdl
			   x=$[x+1]
			fi
		  done
	     done
		fi
	  n=$(( n+1 ))
	  done
	fi
  done
done

echo "$x total files do not exist and have been resubmitted to condor"