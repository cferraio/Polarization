#!/bin/sh


#pt=1
#cpm=1
CONDOR_JOB="runtoymcfitscondor.jdl"

for pt in 2
do
	for cpm in 4 5
	do
		for bg in 7 8 9
		do
			cp condorsubmittoymc.jdl $CONDOR_JOB
			echo "condor-simple.py $pt $cpm $bg" >> $CONDOR_JOB
			echo "Queue 1" >> $CONDOR_JOB	
			condor_submit $CONDOR_JOB
done
done
done