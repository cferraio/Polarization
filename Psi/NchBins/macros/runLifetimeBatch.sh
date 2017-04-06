#!/bin/sh


#rm lifetimelogs/*

for pt in 1 2 
do
	for cpm in 1 2 3 4 5 6 7 8 9 10 11 12
	do
		touch lifetimecondor.jdl
		echo "universe = vanilla" >> lifetimecondor.jdl
		echo "Executable = JobLifetimePrepTTree.sh" >> lifetimecondor.jdl
		echo "should_transfer_files = NO" >> lifetimecondor.jdl
		echo "notification = never" >> lifetimecondor.jdl
		echo "Output = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/lifetimelogs/simple_\$(cluster)_\$(process).stdout" >> lifetimecondor.jdl
		echo "Error  = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/lifetimelogs/simple_\$(cluster)_\$(process).stderr" >> lifetimecondor.jdl
		echo "Log    = /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros/lifetimelogs/simple_\$(cluster)_\$(process).condor" >> lifetimecondor.jdl
		echo "Arguments = $pt $cpm" >> lifetimecondor.jdl
		echo "Queue 1" >> lifetimecondor.jdl	
		condor_submit lifetimecondor.jdl
		rm lifetimecondor.jdl
done
done
