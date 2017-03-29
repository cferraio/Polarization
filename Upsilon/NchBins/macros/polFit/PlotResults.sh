#!/bin/sh

homedir=`pwd`
cd ..
cd ..
basedir=`pwd`
cd macros/polFit
storagedir=`more storagedir`/Data #please define the directory storagedir in the file macros/polFit/storagedir
#storagedir=`more storagedir`/ToyMC #please define the directory storagedir in the file macros/polFit/storagedir

########## INPUTS ##########

for nState in 2;do

JobID=OddvsEven
#additionalName=BGsysPlots
additionalName=_Ups${nState}S
#additionalName=_e_Sig_frame3scen3_Bkg_frame3scen9

PlotMatt=0
PlotCompare=1

PlotAsymm=0
PlotFinalData=1
PlotSystematics=0
PlotLegend=1
DrawLatexStuff=0
PlotBG0plots=0
DeltaTildeplots=0
SBmSigPlots=0
SteerIndividuals=0
BGratioFits=0
BGratioChi2Fits=0
rapBinComb=0
ExtendLegendInX=0
ShiftInX=0
PlotVsComp=0

DefaultID=OddvsEven_All
CompareID1=OddvsEven_Odd
#DefaultID=cutNPriVtx
CompareID2=OddvsEven_Even
#CompareID2=GreatCPMRun2_4CPMBins_withsys
CompareID3=cutNPriVtx_withsys
CompareID4=cutNPriVtx_smallerpT2_Stat_Plus_BG_Er
#DefaultID=Ups2S_fracL46_nSima3
#CompareID1=Ups2S_fracL46_nSima3_withsys
#DefaultID=Ups3S_fracL30_nSima1
#CompareID1=Ups3S_fracL30_nSima3_withsys
#DefaultID=Ups3S_fracL30_nSima3
#CompareID1=Ups3S_fracL30_nSima3_withsys
#CompareID2=GreatCPMRun
nComp=2

LegendEntryDefID=All
LegendEntryCompID1=Odd
LegendEntryCompID2=Even
#LegendEntryDefID=Cut16
#LegendEntryCompID1=Cut10
LegendEntryCompID3=15-50GeV,Corrected,AllSys
LegendEntryCompID4=15-35GeV,Corrected,BGonly


nSystematics=0

ptBinMin=1
ptBinMax=2
cpmBinMin=1
cpmBinMax=5


#SystID1Base=NewFrameworks
#SystID1Specify=FWIII/Ups1S/scen7
#SystID1Title=#lambda_{#theta}^{PX}_0_#lambda_{#phi}^{PX}_0.8
#SystID1ProbDist=1

#SystID2Base=NewFrameworks
#SystID2Specify=FWIII/Ups1S/scen8
#SystID2Title=#lambda_{#theta}^{PX}_2_#lambda_{#phi}^{PX}_0.4
#SystID2ProbDist=1

#SystID3Base=NewFrameworks
#SystID3Specify=FWIII/Ups1S/scen9
#SystID3Title=#lambda_{#theta}^{PX}_4_#lambda_{#phi}^{PX}_-0.4
#SystID3ProbDist=1

SystID1Base=NewFrameworks
SystID1Specify=FWI3S
SystID1Title=Upsilon3S
SystID1ProbDist=1

SystID2Base=NewFrameworks
SystID2Specify=FWI2S
SystID2Title=Upsilon2S
SystID2ProbDist=1

SystID3Base=NewFrameworks
SystID3Specify=FWI1S
SystID3Title=Upsilon1S
SystID3ProbDist=1

#SystID1Base=NewFrameworks
#SystID1Specify=FWII/scen2
#SystID1Title=#lambda_{#theta}^{PX}_-0.5
#SystID1ProbDist=1

#SystID2Base=NewFrameworks
#SystID2Specify=FWII/scen4
#SystID2Title=#lambda_{#theta}^{PX}_+0.5
#SystID2ProbDist=1

#SystID1Base=cutNPriVtx_smallerpT2_BGE_forsystplot
#SystID1Specify=cutNPriVtx_smallerpT2_bgeL_TO_cutNPriVtx_smallerpT2
#SystID1Title=f_{LSB}-28
#SystID1ProbDist=2

#SystID2Base=cutNPriVtx_smallerpT2_BGE_forsystplot
#SystID2Specify=cutNPriVtx_smallerpT2_bgeH_TO_cutNPriVtx_smallerpT2
#SystID2Title=f_{LSB}+28
#SystID2ProbDist=2

#SystID1Base=cutNPriVtx
#  SystID1Specify=cutNPriVtx_FrameworkI/ChangedTGraph/
#  SystID1Title=FrameworkI
#  SystID1ProbDist=1
 # 
#  SystID2Base=cutNPriVtx
#  SystID2Specify=cutNPriVtx_FrameworkII/ChangedTGraph/
#  SystID2Title=FrameworkII
#  SystID2ProbDist=1
 # 
 # SystID3Base=cutNPriVtx
  #SystID3Specify=cutNPriVtx_FrameworkIII/ChangedTGraph/
 # SystID3Title=FrameworkIII
 # SystID3ProbDist=1
 # 
  #SystID4Base=cutNPriVtx
  #SystID4Specify=cutNPriVtx_Parametrization/ChangedTGraph/
 # SystID4Title=Parametrization
 # SystID4ProbDist=1
 # 
#  SystID5Base=cutNPriVtx
#  SystID5Specify=cutNPriVtx_RhoFactor/ChangedTGraph/
#  SystID5Title=RhoFactor
#  SystID5ProbDist=1
 # 
#  SystID6Base=cutNPriVtx
#  SystID6Specify=cutNPriVtx_TnP_model/ChangedTGraph/
#  SystID6Title=TnP_model
#  SystID6ProbDist=1
# # 
#  SystID7Base=cutNPriVtx_BGsyst
# # SystID7Base=cutNPriVtx_BGsyst_4cpmbins
#  SystID7Specify=cutNPriVtx_fLSB100_TO_cutNPriVtx_fLSB44/
# SystID7Specify=cutNPriVtx_fLSB74_TO_cutNPriVtx_fLSB18/
# SystID7Specify=cutNPriVtx_fLSB59_TO_cutNPriVtx_fLSB2/
#SystID7Specify=cutNPriVtx_4cpmbins_fLSB59_TO_cutNPriVtx_4cpmbins_fLSB2/
#  SystID7Title=BKGmodel
#  SystID7ProbDist=2

########################################

cd ${homedir}

touch PlotFinalResults.cc
make

mkdir FinalResults
mkdir FinalResults/${JobID}

JobIDDir=FinalResults/${JobID}

mkdir ${JobIDDir}


./PlotFinalResults ${DefaultID}=DefaultID ${CompareID1}=CompareID1 ${CompareID2}=CompareID2 ${CompareID3}=CompareID3 ${CompareID4}=CompareID4 ${JobID}=JobID ${SystID1Base}=SystID1Base ${SystID1Specify}=SystID1Specify ${SystID1Title}=SystID1Title ${SystID2Base}=SystID2Base ${SystID2Specify}=SystID2Specify ${SystID2Title}=SystID2Title ${basedir}=basedir ${storagedir}=storagedir ${cpmBinMin}cpmBinMin ${cpmBinMax}cpmBinMax ${ptBinMin}ptBinMin ${ptBinMax}ptBinMax ${nSystematics}nSystematics ${nComp}nComp ${nState}nState ${SystID3Base}=SystID3Base ${SystID3Specify}=SystID3Specify ${SystID3Title}=SystID3Title ${SystID4Base}=SystID4Base ${SystID4Specify}=SystID4Specify ${SystID4Title}=SystID4Title ${SystID5Base}=SystID5Base ${SystID5Specify}=SystID5Specify ${SystID5Title}=SystID5Title ${SystID6Base}=SystID6Base ${SystID6Specify}=SystID6Specify ${SystID6Title}=SystID6Title ${SystID7Base}=SystID7Base ${SystID7Specify}=SystID7Specify ${SystID7Title}=SystID7Title ${SystID8Base}=SystID8Base ${SystID8Specify}=SystID8Specify ${SystID8Title}=SystID8Title PlotMatt=${PlotMatt} PlotAsymm=${PlotAsymm} PlotCompare=${PlotCompare} PlotFinalData=${PlotFinalData} PlotSystematics=${PlotSystematics} PlotLegend=${PlotLegend} PlotBG0plots=${PlotBG0plots} DeltaTildeplots=${DeltaTildeplots} SBmSigPlots=${SBmSigPlots} CompareSyst=${CompareSyst} SteerIndividuals=${SteerIndividuals} BGratioFits=${BGratioFits} BGratioChi2Fits=${BGratioChi2Fits} rapBinComb=${rapBinComb} SetCompStyle=${SetCompStyle} ${LegendEntryDefID}=LegendEntryDefID ${LegendEntryCompID1}=LegendEntryCompID1 ${LegendEntryCompID2}=LegendEntryCompID2 ${LegendEntryCompID3}=LegendEntryCompID3 ${LegendEntryCompID4}=LegendEntryCompID4 ExtendLegendInX=${ExtendLegendInX} ShiftInX=${ShiftInX} PlotVsComp=${PlotVsComp} DrawLatexStuff=${DrawLatexStuff}

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