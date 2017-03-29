#!/bin/sh

homedir=`pwd`
cd ..
cd ..
basedir=`pwd`
cd macros/polFit
storagedir=`more storagedir`/Data #please define the directory storagedir in the file macros/polFit/storagedir
datadir_Start=${basedir}/macros/DataFiles

########## INPUTS ##########

for nState in 3;do

JobID=cutNPriVtx_4cpmbins_Stats_BG_only #Please define nSigma and fracL yourself in the JobID, if needed

rapBinMin=1
rapBinMax=1
ptBinMin=1
ptBinMax=1
cpmBinMin=1
cpmBinMax=4

nFits=50
MPValgo=3 		#1...mean,2...gauss,3...gauss-loop with chi2<2

########################################

fracL=72 #in percent
nSigma=1.00 #needed in 2 decimal accuracy (x.yz)

nEff=1030
UseMCeff=true

nDileptonEff=1
UseMCDileptoneff=true

nRhoFactor=1

nSample=50000

nSkipGen=0

DataID=_cutNPriVtx_Stats_BG_only

datadir=${datadir_Start}/SetOfCuts${FidCuts}${DataID}/AllStates_${nSigma}Sigma_FracLSB${fracL}Percent

TreeID=${nState}SUps

cd ${homedir}

polScenSig=3
polScenBkg=3
frameSig=1
frameBkg=1
ConstEvents=15000
UseConstEv=true
nGenerations=${nFits}
gen=false
rec=false
fit=false
plot=true
NewAccCalc=false


touch polGenRecFitPlot.cc
make

ScenDir=Default_ScenDir
mkdir ${storagedir}
mkdir ${storagedir}/${JobID}

cp ${basedir}/macros/polFit/polGenRecFitPlot ${storagedir}/${JobID}/polGenRecFitPlot
cp ${basedir}/macros/polFit/polGen.C ${storagedir}/${JobID}/polGen.C
cp ${basedir}/macros/polFit/polRec.C ${storagedir}/${JobID}/polRec.C
cp ${basedir}/macros/polFit/polFit.C ${storagedir}/${JobID}/polFit.C
cp ${basedir}/macros/polFit/polPlot.C ${storagedir}/${JobID}/polPlot.C

cd ${storagedir}/${JobID}


rap_=${rapBinMin}
while [ $rap_ -le ${rapBinMax} ]
do
pT_=${ptBinMin}
while [ $pT_ -le ${ptBinMax} ]
do
cpm_=${cpmBinMin}
while [ $cpm_ -le ${cpmBinMax} ]
do


nGen_=${nSkipGen}
nGen_=$((nGen_+1))
nMaxGen=$((nGenerations+nSkipGen))
while [ $nGen_ -le $nMaxGen ]
do



cp ${storagedir}/${JobID}/polGenRecFitPlot ${storagedir}/${JobID}/polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm_}
./polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm_} ${nGen_}ThisGen ${JobID}=JobID ${storagedir}=storagedir ${basedir}=basedir ${nGenerations}nGenerations ${polScenSig}polScenSig ${frameSig}frameSig ${polScenBkg}polScenBkg ${frameBkg}frameBkg ${rap_}rapBinMin ${rap_}rapBinMax ${pT_}ptBinMin ${pT_}ptBinMax ${cpm_}cpmBinMin ${cpm_}cpmBinMax ${nEff}nEff ${nDileptonEff}nDiEff ${FidCuts}FidCuts ${nSample}nSample ${ConstEvents}ConstEvents ${nSkipGen}nSkipGen UseConstEv=${UseConstEv} gen=${gen} rec=${rec} fit=${fit} plot=${plot} ${TreeID}=TreeID ${datadir}=realdatadir UseMCeff=${UseMCeff} UseMCDileptoneff=${UseMCDileptoneff} ${nRhoFactor}nRhoFactor ${MPValgo}MPValgo NewAccCalc=${NewAccCalc}
rm polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm_}

mv Figures/fit_CS_costh_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf Figures/fit_CS_costh_Fit${nGen_}_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf
mv Figures/fit_CS_phi_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf Figures/fit_CS_phi_Fit${nGen_}_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf
mv Figures/fit_CS_phith_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf Figures/fit_CS_phith_Fit${nGen_}_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf
mv Figures/fit_HX_costh_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf Figures/fit_HX_costh_Fit${nGen_}_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf
mv Figures/fit_HX_phi_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf Figures/fit_HX_phi_Fit${nGen_}_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf
mv Figures/fit_HX_phith_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf Figures/fit_HX_phith_Fit${nGen_}_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf
mv Figures/fit_PX_costh_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf Figures/fit_PX_costh_Fit${nGen_}_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf
mv Figures/fit_PX_phi_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf Figures/fit_PX_phi_Fit${nGen_}_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf
mv Figures/fit_PX_phith_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf Figures/fit_PX_phith_Fit${nGen_}_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf
mv Figures/lph_vs_lth_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf Figures/lph_vs_lth_Fit${nGen_}_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf
mv Figures/lphstar_vs_lthstar_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf Figures/lphstar_vs_lthstar_Fit${nGen_}_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf
mv Figures/ltp_vs_lph_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf Figures/ltp_vs_lph_Fit${nGen_}_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf
mv Figures/ltp_vs_lth_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf Figures/ltp_vs_lth_Fit${nGen_}_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf
mv Figures/ltilde_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf Figures/ltilde_Fit${nGen_}_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf

mv Figures/fit_cosalpha_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf Figures/fit_CS_cosalpha_Fit${nGen_}_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf
mv Figures/fit_background_rap_test_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf Figures/fit_CS_background_rap_test_Fit${nGen_}_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf
mv Figures/fit_background_mass_test_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf Figures/fit_CS_background_mass_test_Fit${nGen_}_${nState}SUps_mass${mass_}_pT${pT_}_cpm${cpm_}.pdf
mv Figures/fit_background_pT_test_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf Figures/fit_CS_background_pT_test_Fit${nGen_}_${nState}SUps_pT${pT_}_pT${pT_}_cpm${cpm_}.pdf
mv Figures/fit_background_phiPX_test_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf Figures/fit_CS_background_phiPX_test_Fit${nGen_}_${nState}SUps_phiPX${phiPX_}_pT${pT_}_cpm${cpm_}.pdf
mv Figures/fit_background_costhPX_test_${nState}SUps_rap${rap_}_pT${pT_}_cpm${cpm_}.pdf Figures/fit_CS_background_costhPX_test_Fit${nGen_}_${nState}SUps_costhPX${costhPX_}_pT${pT_}_cpm${cpm_}.pdf






nGen_=$((nGen_+1))
done


cp ${storagedir}/${JobID}/polGenRecFitPlot ${storagedir}/${JobID}/polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm_}
./polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm_} ${nGen_}ThisGen ${JobID}=JobID ${storagedir}=storagedir ${basedir}=basedir ${nGenerations}nGenerations ${polScenSig}polScenSig ${frameSig}frameSig ${polScenBkg}polScenBkg ${frameBkg}frameBkg ${rap_}rapBinMin ${rap_}rapBinMax ${pT_}ptBinMin ${pT_}ptBinMax ${cpm_}cpmBinMin ${cpm_}cpmBinMax ${nEff}nEff ${nDileptonEff}nDiEff ${FidCuts}FidCuts ${nSample}nSample ${ConstEvents}ConstEvents ${nSkipGen}nSkipGen UseConstEv=${UseConstEv} gen=false rec=false fit=false plot=${plot} ${TreeID}=TreeID ${datadir}=realdatadir UseMCeff=${UseMCeff} UseMCDileptoneff=${UseMCDileptoneff} ${nRhoFactor}nRhoFactor ${MPValgo}MPValgo scalePlots=true NewAccCalc=${NewAccCalc}
rm polGenRecFitPlot_rap${rap_}_pt${pT_}_cpm${cpm_}


cpm_=$((cpm_+1))
done
pT_=$((pT_+1))
done
rap_=$((rap_+1))
done


done

rm *.so
rm *.d
#rm polGenRecFitPlot

mkdir ../tmp
#mv *.C ../tmp

