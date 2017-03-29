#!/bin/sh

cd ..
cd ..
basedir=`pwd`
cd macros/polFit
storagedir=`more storagedir`/ToyMC #please define the directory storagedir in the file macros/polFit/storagedir

########## INPUTS ##########



for JobID in 15to20;do

echo ${JobID}

nState=1

ptBinMin=2
ptBinMax=2
cpmBinMin=4
cpmBinMax=5

frameSig=3
for polScenSig in 3;do

frameBkg=3
for polScenBkg in 7 8 9;do

nGenerations=50

MPValgo=3 		#1...mean,2...gauss,3...gauss-loop with chi2<2
additionalName=MPV${MPValgo}

############################

TreeID=${nState}SUps

cd ${basedir}/macros/polFit

rapBinMin=1 #don't change
rapBinMax=1 #don't change

ScenDir=Sig_frame${frameSig}scen${polScenSig}_Bkg_frame${frameBkg}scen${polScenBkg}

mkdir ${basedir}/macros/polFit/FiguresToyMC
mkdir ${basedir}/macros/polFit/FiguresToyMC/${JobID}
mkdir ${basedir}/macros/polFit/FiguresToyMC/${JobID}/${ScenDir}

touch polRapPtPlot.cc
 
make

cd ${storagedir}/${JobID}
mkdir ${ScenDir}

cp ${basedir}/macros/polFit/polRapPtPlot .


./polRapPtPlot ${cpmBinMin}cpmBinMin ${cpmBinMax}cpmBinMax ${ptBinMin}ptBinMin ${ptBinMax}ptBinMax ${rapBinMin}rapBinMin ${rapBinMax}rapBinMax ${frameSig}frameSig ${polScenSig}polScen ${MPValgo}MPValgo ${nGenerations}nGenerations ${ScenDir}=dirstruct ${nState}nState

mv ${ScenDir}/TGraphResults_${TreeID}_temp.root ${ScenDir}/TGraphResults_${TreeID}.root 

cp ${basedir}/latex/PullSummaryResults.tex ${ScenDir}/PullSummaryResults_${ScenDir}.tex
cp ${basedir}/latex/ParameterSummaryResults.tex ${ScenDir}/ParameterSummaryResults_${ScenDir}.tex
cp ${basedir}/latex/ToyResults.tex ${ScenDir}/ToyResults_${ScenDir}.tex

pdflatex ToyNumericalResults_${ScenDir}.tex
mv ToyNumericalResults_${ScenDir}.pdf ${basedir}/macros/polFit/FiguresToyMC/${JobID}/${ScenDir}/ToyNumericalResults_${ScenDir}_${additionalName}.pdf
rm *.aux
rm *.log

cd ${ScenDir}
pdflatex PullSummaryResults_${ScenDir}.tex
pdflatex ParameterSummaryResults_${ScenDir}.tex

rap_=${rapBinMin}
while [ $rap_ -le ${rapBinMax} ]
do
pT_=${ptBinMin}
while [ $pT_ -le ${ptBinMax} ]
do
cpm_=${cpmBinMin}
while [ $cpm_ -le ${cpmBinMax} ]
do


pdflatex "\newcommand\rappt{rap${rap_}pt${pT_}cpm${cpm_}}\input{ToyResults_${ScenDir}.tex}"
mv ToyResults_${ScenDir}.pdf ${basedir}/macros/polFit/FiguresToyMC/${JobID}/${ScenDir}/ToyResults_${ScenDir}_rap${rap_}pt${pT_}cpm${cpm_}_${additionalName}.pdf

cpm_=$((cpm_+1))
done
pT_=$((pT_+1))
done
rap_=$((rap_+1))
done

mv PullSummaryResults_${ScenDir}.pdf ${basedir}/macros/polFit/FiguresToyMC/${JobID}/${ScenDir}/PullSummaryResults_${ScenDir}_${additionalName}.pdf
mv ParameterSummaryResults_${ScenDir}.pdf ${basedir}/macros/polFit/FiguresToyMC/${JobID}/${ScenDir}/ParameterSummaryResults_${ScenDir}_${additionalName}.pdf

rm *.aux
rm *.log
rm *.tex

cd ..
rm polRapPtPlot

done
done
done
