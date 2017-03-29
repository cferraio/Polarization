#!/bin/sh

homedir=`pwd`
cd ..
cd ..
basedir=`pwd`
cd macros/polFit
storagedir=`more storagedir`/Data #please define the directory storagedir in the file macros/polFit/storagedir

########## INPUTS ##########

for nState in 1;do

JobID=RedoPlots
additionalName=_NewSuppMat_Ups${nState}S #SystBkgNew for centrals

PlotMatt=0
PlotMattForICHEP=0
PlotCompare=0

PlotAsymm=0
PlotFinalData=1
PlotSystematics=0
PlotLegend=0
PlotBrazilian=0 
FitGraph=0
DrawLatexStuff=1
DrawPreliminary=1
MultiPanelPlots=1
MPCentralsWithTotalSystID=cutNPriVtx_smallerpT2_FinalSyst_Glob
#Aug11Centrals_CentralsFromAlteredPPD_1SigmaStatError #June20Centrals_CentralsFromAlteredPPDJune20_1SigmaStatError #May11Centrals_CentralsFromAlteredPPDMay17_1SigmaStatErrorRelative #May11CentralWithTotalSyst #May11CentralWithTotalSyst May11NewTTreeCentralWithTotalSyst Apr27CentralWithTotalSyst
PlotAlteredPPDResults=1
PlotAllLambdas=1
PlotGlobalUnc=1
GlobalUncLoc=cutNPriVtx_smallerpT2_FinalSyst

#UncommentIFplotSystOverview
#PlotFinalData=0
#PlotSystematics=1
#PlotLegend=1
#PlotBrazilian=0
#FitGraph=0
#DrawLatexStuff=1
#MultiPanelPlots=0

#UncommentIFplotCDFComparison
#PlotMatt=1
#PlotCompare=1
#PlotAsymm=0
#PlotFinalData=1
#PlotSystematics=0
#PlotLegend=0
#PlotBrazilian=0
#FitGraph=0
#DrawLatexStuff=1
#MultiPanelPlots=1


DefaultID=cutNPriVtx_smallerpT2_FinalSyst
#CompareID1=Ups3S_fracL30_nSima3_withsys
#CompareID2=
nComp=0

#DefaultID=Data_TowardsPRL_Aug11_FinalResults_1Sigma_AlteredPPD_BKGlinPLUSRestSquaredGauss_5nRand_BiasCorrection_1S2S3SAug12_1Sig #Data_TheGreatApproval_June17_NewestCentrals_SOFT_SOFT_AlteredPPD_June20_BKGlinPLUSRestSquaredGauss_5nRand
#CompareID1=Data_TheGreatRun_10B_May11_NewestCentrals
#CompareID2=Data_TheGreatRun_10B_May11_NewestCentrals_AlteredPPD_May17_BKGlinPLUSRestSquaredGauss_10nRand
#CompareID3=BG0_Mar19_HighCtauSigCheck3p25
#CompareID4=BG0_Mar19_HighCtauSigCheck3p5
#nComp=0


nSystematics=0

#SystID1Base=GreatCPMRunAverage2
#SystID1Specify=GreatCPMRun_FrameworkI_nSigma1/ChangedTGraph/
#SystID1Title=FrameworkI

#SystID2Base=GreatCPMRunAverage2
#SystID2Specify=GreatCPMRun_FrameworkII_nSigma1/ChangedTGraph/
#SystID2Title=FrameworkII

#SystID3Base=GreatCPMRunAverage2
#SystID3Specify=GreatCPMRun_FrameworkIII_nSigma1/ChangedTGraph/
#SystID3Title=FrameworkIII

#SystID4Base=GreatCPMRunAverage
#SystID4Specify=CPM_FinalRun_Kinematics/ChangedTGraph/
#SystID4Title=Kin
#SystID4ProbDist=1

#SystID5Base=GreatCPMRunAverage2
#SystID5Specify=GreatCPMRun_Parametrization_nSigma1/ChangedTGraph/
#SystID5Title=Parametrization

#SystID6Base=GreatCPMRunAverage2
#SystID6Specify=GreatCPMRun_RhoFactor_nSigma1/ChangedTGraph/
#SystID6Title=RhoFactor

#SystID4Base=GreatCPMRunAverage2
#SystID4Specify=GreatCPMRun_TnP_model_nSigma1/ChangedTGraph/
#SystID4Title=TnP_model

#SystID7Base=GreatCPMRun2BGSyst
#SystID7Base=GreatCPMRun2BGSyst_4CPMBins
#SystID7Specify=GreatCPMRun2_FracL100_TO_GreatCPMRun2_FracL44/
#SystID7Specify=GreatCPMRun2_FracL74_TO_GreatCPMRun2_FracL18/
#SystID7Specify=GreatCPMRun2_fracL59_TO_GreatCPMRun2_fracL2
#SystID7Specify=GreatCPMRun2_4CPMBins_fracL59_TO_GreatCPMRun2_4CPMBins_fracL2
#SystID7Specify=Ups3S_fracL59_nSima1_TO_Ups3S_fracL2_nSima1/
#SystID7Title=BKGmodel

cpmBinMin=1
cpmBinMax=5

ptBinMin=1
ptBinMax=2



########################################

cd ${homedir}

touch PlotFinalResults.cc
make

mkdir FinalResults
mkdir FinalResults/${JobID}

JobIDDir=FinalResults/${JobID}

mkdir ${JobIDDir}


./PlotFinalResults GlobalUncLoc=${GlobalUncLoc} PlotGlobalUnc=${PlotGlobalUnc} PlotAlteredPPDResults=${PlotAlteredPPDResults} PlotAllLambdas=${PlotAllLambdas} MultiPanelPlots=${MultiPanelPlots} DrawLatexStuff=${DrawLatexStuff} ${MPCentralsWithTotalSystID}=MPCentralsWithTotalSystID ${GlobalUncLoc}=GlobalUncLoc ${DefaultID}=DefaultID ${CompareID1}=CompareID1 ${CompareID2}=CompareID2 ${CompareID3}=CompareID3 ${CompareID4}=CompareID4 ${JobID}=JobID ${SystID1Base}=SystID1Base ${SystID1Specify}=SystID1Specify ${SystID1Title}=SystID1Title ${SystID2Base}=SystID2Base ${SystID2Specify}=SystID2Specify ${SystID2Title}=SystID2Title ${basedir}=basedir ${storagedir}=storagedir ${ptBinMin}ptBinMin ${ptBinMax}ptBinMax ${cpmBinMin}cpmBinMin ${cpmBinMax}cpmBinMax ${nSystematics}nSystematics ${nComp}nComp ${nState}nState ${SystID3Base}=SystID3Base ${SystID3Specify}=SystID3Specify ${SystID3Title}=SystID3Title ${SystID4Base}=SystID4Base ${SystID4Specify}=SystID4Specify ${SystID4Title}=SystID4Title ${SystID5Base}=SystID5Base ${SystID5Specify}=SystID5Specify ${SystID5Title}=SystID5Title ${SystID6Base}=SystID6Base ${SystID6Specify}=SystID6Specify ${SystID6Title}=SystID6Title ${SystID7Base}=SystID7Base ${SystID7Specify}=SystID7Specify ${SystID7Title}=SystID7Title ${SystID8Base}=SystID8Base ${SystID8Specify}=SystID8Specify ${SystID8Title}=SystID8Title PlotMatt=${PlotMatt} PlotAsymm=${PlotAsymm} PlotCompare=${PlotCompare} PlotFinalData=${PlotFinalData} PlotSystematics=${PlotSystematics} PlotLegend=${PlotLegend} PlotBrazilian=${PlotBrazilian} FitGraph=${FitGraph} DrawPreliminary=${DrawPreliminary} PlotMattForICHEP=${PlotMattForICHEP}

cd ${homedir}/FinalResults/${JobID}/${nState}SUps
if [ ${PlotFinalData} -eq 1 ]
then
cp ${basedir}/latex/FinalDataResults.tex .
pdflatex FinalDataResults.tex
mv FinalDataResults.pdf FinalDataResults${additionalName}.pdf
fi
if [ ${PlotSystematics} -eq 1 ]
then
cp ${basedir}/latex/Systematics.tex .
pdflatex Systematics.tex
mv Systematics.pdf Systematics${additionalName}.pdf
fi
rm *.aux
rm *.log
rm *.tex

#rm -r Figures${additionalName}
mkdir Figures${additionalName}
mv Figures/* Figures${additionalName}/

done

