#!/bin/sh

export VO_CMS_SW_DIR=/sharesoft/cmssw #comment out for non-condor
. $VO_CMS_SW_DIR/cmsset_default.sh #comment out for non-condor
cd /home/ferraioc/PolNew/CMSSW_5_3_20/src/Psi/NchBins/macros #comment out for non-condor
eval `scramv1 runtime -sh` #comment out for non-condor

source /cvmfs/sft.cern.ch/lcg/app/releases/ROOT/5.34.05/x86_64-slc5-gcc43-opt/root/bin/thisroot.sh  
source /cvmfs/sft.cern.ch/lcg/app/releases/ROOT/5.34.05/x86_64-slc5-gcc43-opt/root/bin/setxrd.sh /cvmfs/sft.cern.ch/lcg/external/xrootd/3.2.4/x86_64-slc5-gcc46-opt/

####to 2D histos in createWorkspace.C only work with the following, use ONLY to make those plots, then go back to the above ROOT version for everything else
#source /cvmfs/sft.cern.ch/lcg/app/releases/ROOT/5.30.05/x86_64-slc5-gcc43-opt/root/bin/thisroot.sh                                     


#homedir=HOMEDIR
#cd ${homedir}
Cdir=$PWD

cd ..
basedir=$PWD
cd macros

# input arguments
for nState in 4;do    #1,2,3,Upsi(1S,2S,3S); 4,Jpsi 5,PsiPrime
for FidCuts in 11;do #defines the set of cuts to be used, see macros/polFit/effsAndCuts.h
cd $Cdir

if [ ${nState} -eq 4 ] 
then
rapMin=1     #takes bins, not actual values
rapMax=1     #if you only want to process 1 y bin, rapMax = rapMin
ptMin=$1      #takes bins, not acutal values
ptMax=$1      #if you only want to process 1 pt bin, ptMax = ptMin
cpmMin=$2
cpmMax=$2
Plotting=1   #plotting macro: 1 = plot all, 2 = plot mass, 3 = plot lifetime sidebands, 4 = plot lifetime singal region, 
	           # 5 = sidebands, separate pull and distribution, 6 = signal region, separate pull and distribution
fi

if [ ${nState} -eq 5 ] 
then
rapMin=1     #takes bins, not actual values
rapMax=1     #if you only want to process 1 y bin, rapMax = rapMin
ptMin=$1      #takes bins, not acutal values
ptMax=$1      #if you only want to process 1 pt bin, ptMax = ptMin
cpmMin=$2
cpmMax=$2
Plotting=1   #plotting macro: 1 = plot all, 2 = plot mass, 3 = plot lifetime sidebands, 4 = plot lifetime singal region, 
	           # 5 = sidebands, separate pull and distribution, 6 = signal region, separate pull and distribution
fi

rejectCowboys=true
RequestTrigger=true
MC=false
officialMC=false
correctCtau=false   #correct pseudo-proper lifetime to l_new = l * MpsiPDG / Mpsi, with l = Lxy * Mpsi / pT
drawRapPt2D=false  #draw Rap-Pt 2D map of Psi (change root settings above)
drawPtCPM2D=false  #draw Pt-CPM 2D map of Psi (change root settings above)

doCtauUncer=true
PolLSB=false       #measure polarization of the left sideband
PolRSB=false       #measure polarization of the right sideband
PolNP=false        #measure polarization of the non prompt events
forceBinning=true  #set binning of Psi1S consistently to non prompt binning and Psi2S consistently to background binning
folding=true       #folding is applied to all background histograms
normApproach=false #normalization 
ctauScen=5         #0:default(1s:2.5,2s:2.0), 1:(1s:3.5,2s:3.0), 2:(1s:1.5,2s:1.0), 3:100mm 1S and 2S, 
FracLSB=-1         #-1:defalut, 0, 100
scaleFracBg=false ##what is this for?
fitMassPR=false
fitMassNP=false
fitmass2gaus=true #does mass fit with either double gaussian (true) or 1 gaus with rapidity dependent sigma (false). rap dep sigma could be best for wider rap bins

DataID=Psi$[nState-3]S_ctauScen${ctauScen}_FracLSB${FracLSB}
polDataPath=${basedir}/Psi/Data/${DataID}


#Define JobID
JobIDName=FourthResults_ForPreApproval #2012datarun #change job id name here, automatically updates below
JobID=ctauScen${ctauScen}_FracLSB${FracLSB}_${JobIDName} #updates automatically

# input files
# In case of more input Files: define inputTreeX and adapt the line starting with inputTrees, at the moment up to 4 files implemented
if [ ${nState} -eq 4 ] 
then
inputTree1=/data/users/ferraioc/TTree_Onia2MuMu_v30_PromptRecoAB_10May2012_Jpsi.root
#inputTree1=/data/users/ferraioc/Polarization/r2012A_DoubMuPk_jpsi_v6.root
#inputTree2=/data/users/ferraioc/Polarization/r2012B_MuPk_jpsi_v6.root
#inputTree3=/data/users/ferraioc/Polarization/r2012C_MuPk_jpsi_v6.root
#inputTree4=/data/users/ferraioc/Polarization/r2012D_MuPk_jpsi_v6.root
if [ ${MC} = 'true' ]
then
inputTree1=/scratch/ikratsch/Polarization/Jpsi/InputFiles/TTree_Psi1S_Gun_Pt9p5_70p5_19Dec2012.root
fi
if [ ${officialMC} = 'true' ]
then
inputTree1=/data/users/ferraioc/Polarization/2012ppOniaData/onia2MuMu_tree_validation.root
fi
fi

if [ ${nState} -eq 5 ]
then
inputTree1=/data/users/ferraioc/TTree_Onia2MuMu_v30_PromptRecoAB_10May2012_Psi.root
if [ ${MC} = 'true' ]
then
inputTree1=/scratch/ikratsch/Polarization/Jpsi/InputFiles/TTree_Psi2S_Gun_Pt6p5_50p5_19Dec2012.root
fi
fi

################ EXECUTABLES #################

#following flags decide if the step is executed (1) or not (0):
#IMPORTANT: for MC set execute_runWorkspace, execute_MassFit and execute_runLifetimeFit to 0
execute_runData=0			           #independent of rapMin, rapMax, ptMin, ptMax
execute_runWorkspace=0			     #independent of rapMin, rapMax, ptMin, ptMax
execute_runMassFit=0			       #can be executed for different pt and y bins
execute_runLifetimeFit=0        #can be executed for different pt and y bins
execute_runPlotMassLifetime=1    #can be executed for different pt and y bins
execut_PlotFitPar=0              #independent of rapMin, rapMax, ptMin, ptMax
execute_runBkgHistos=0           #can be executed for different pt and y bins
execute_PlotCosThetaPhiBG=0 		 #This step only has to be executed once for each set of cuts (indep. of FracLSB and nSigma)
execute_PlotCosThetaPhiDistribution=0 #This step only has to be executed once for each set of cuts (indep. of FracLSB and nSigma)

#################################

# Make directories
CutDir=${Cdir}/DataFiles/SetOfCuts${FidCuts}_${JobID}

WorkDir=${CutDir}/Psi$[nState-3]S
mkdir -p ${CutDir}
mkdir -p ${WorkDir}
cp ../interface/commonVar_Psi$[nState-3]S.h ${WorkDir}/commonVar.h 

mkdir -p DataFiles
mkdir -p ${WorkDir}/tmpFiles/backupWorkSpace
mkdir -p ${WorkDir}/Figures
mkdir -p ${WorkDir}/PDF
mkdir -p ${WorkDir}/Fit

# Copy files to directory
cp Makefile ${WorkDir}/Makefile
cp ../interface/rootIncludes.inc ${WorkDir}/rootIncludes.inc

cp runData.cc ${WorkDir}/runData.cc
cp PolData.C ${WorkDir}/PolData.C
cp PolData.h ${WorkDir}/PolData.h
cp ../interface/effsAndCuts_Psi$[nState-3]S.h ${WorkDir}/effsAndCuts.h

cp runWorkspace.cc ${WorkDir}/runWorkspace.cc
cp createWorkspace.C ${WorkDir}/createWorkspace.C

cp runMassFit.cc ${WorkDir}/runMassFit.cc
cp massFit.cc ${WorkDir}/massFit.cc
if [ ${fitmass2gaus} = 'true' ]
then
cp massFit_2gaus.cc ${WorkDir}/massFit.cc
fi

cp runLifetimeFit.cc ${WorkDir}/runLifetimeFit.cc
cp lifetimeFit.cc ${WorkDir}/lifetimeFit.cc
if [ ${fitmass2gaus} = 'true' ]
then
cp lifetimeFit_2gaus.cc ${WorkDir}/lifetimeFit.cc
fi
cp ../interface/calculatePar.cc ${WorkDir}/calculatePar.cc
cp ../interface/RooUtils.h ${WorkDir}/RooUtils.h

cp runPlotMassLifetime.cc ${WorkDir}/runPlotMassLifetime.cc
cp PlotMassLifetime.cc ${WorkDir}/PlotMassLifetime.cc

cp PlotFitPar.cc ${WorkDir}/PlotFitPar.cc

cp runBkgHistos.cc ${WorkDir}/runBkgHistos.cc
cp bkgHistos.C ${WorkDir}/bkgHistos.C
cp calcPol.C ${WorkDir}/calcPol.C

cp PlotCosThetaPhiBG.cc ${WorkDir}/PlotCosThetaPhiBG.cc
cp PlotCosThetaPhiDistribution.cc ${WorkDir}/PlotCosThetaPhiDistribution.cc

cp ../latex/Mass_fitParameter.tex ${WorkDir}/Mass_fitParameter.tex
cp ../latex/Lifetime_fitParameter.tex ${WorkDir}/Lifetime_fitParameter.tex
cp ../latex/myStyle.tex ${WorkDir}/myStyle.tex
cp ../latex/evaluateCtau.tex ${WorkDir}/evaluateCtau.tex
cp ../latex/NumEvents.tex ${WorkDir}/NumEvents.tex

cp ../latex/cosThetaPhi_$[nState-3]S_BG.tex        ${WorkDir}/cosThetaPhi_$[nState-3]S_BG.tex
cp ../latex/cosThetaPhi_$[nState-3]S_BG_highct.tex ${WorkDir}/cosThetaPhi_$[nState-3]S_BG_highct.tex
cp ../latex/cosThetaPhi_$[nState-3]S_NPBG.tex      ${WorkDir}/cosThetaPhi_$[nState-3]S_NPBG.tex
cp ../latex/cosThetaPhi_$[nState-3]S_TBG.tex       ${WorkDir}/cosThetaPhi_$[nState-3]S_TBG.tex
cp ../latex/cosThetaPhi_$[nState-3]S.tex           ${WorkDir}/cosThetaPhi_$[nState-3]S.tex
cp ../latex/MassLifetime_Psi$[nState-3]S.tex       ${WorkDir}/MassLifetime_Psi$[nState-3]S.tex

cd ${WorkDir}

make

inputTrees="inputTree=${inputTree1} inputTree=${inputTree2} inputTree=${inputTree3} inputTree=${inputTree4}"
if [ ${execute_runData} -eq 1 ]
then
./runData ${inputTrees} rejectCowboys=${rejectCowboys} FidCuts=${FidCuts} nState=${nState} MC=${MC} RequestTrigger=${RequestTrigger}
fi

if [ ${execute_runWorkspace} -eq 1 ]
then
./runWorkspace nState=${nState} correctCtau=${correctCtau} drawRapPt2D=${drawRapPt2D} drawPtCPM2D=${drawPtCPM2D}
fi

if [ ${execute_runMassFit} -eq 1 ]
then
rootfile=fit_Psi$[nState-3]S_rap${rapMin}_pt${ptMin}_cpm${cpmMin}.root
cp tmpFiles/backupWorkSpace/fit_Psi$[nState-3]S* tmpFiles/
cp runMassFit runMassFit_$[nState-3]S_rap${rapMin}_pt${ptMin}_cpm${cpmMin}
./runMassFit_$[nState-3]S_rap${rapMin}_pt${ptMin}_cpm${cpmMin} rapMin=${rapMin} rapMax=${rapMax} ptMin=${ptMin} ptMax=${ptMax} cpmMin=${cpmMin} cpmMax=${cpmMax} nState=${nState} fitMassPR=${fitMassPR} fitMassNP=${fitMassNP}
rm runMassFit_$[nState-3]S_rap${rapMin}_pt${ptMin}_cpm${cpmMin}
fi

if [ ${execute_runLifetimeFit} -eq 1 ]
then
cp runLifetimeFit runLifetimeFit_$[nState-3]S_rap${rapMin}_pt${ptMin}_cpm${cpmMin}
./runLifetimeFit_$[nState-3]S_rap${rapMin}_pt${ptMin}_cpm${cpmMin} rapMin=${rapMin} rapMax=${rapMax} ptMin=${ptMin} ptMax=${ptMax} cpmMin=${cpmMin} cpmMax=${cpmMax} nState=${nState}
rm runLifetimeFit_$[nState-3]S_rap${rapMin}_pt${ptMin}_cpm${cpmMin}
fi

if [ ${execute_runPlotMassLifetime} -eq 1 ]
then
cp runPlotMassLifetime runPlotMassLifetime_$[nState-3]S_rap${rapMin}_pt${ptMin}_cpm${cpmMin}
./runPlotMassLifetime_$[nState-3]S_rap${rapMin}_pt${ptMin}_cpm${cpmMin} rapMin=${rapMin} rapMax=${rapMax} ptMin=${ptMin} ptMax=${ptMax} cpmMin=${cpmMin} cpmMax=${cpmMax} nState=${nState} Plotting=${Plotting} fitmass2gaus=${fitmass2gaus}
rm runPlotMassLifetime_$[nState-3]S_rap${rapMin}_pt${ptMin}_cpm${cpmMin}
pdflatex MassLifetime_Psi$[nState-3]S.tex
mv MassLifetime_Psi$[nState-3]S.pdf PDF/MassLifetime_Psi$[nState-3]S.pdf
fi

if [ ${execut_PlotFitPar} -eq 1 ]
then
./PlotFitPar nState=${nState} doCtauUncer=${doCtauUncer} fitmass2gaus=${fitmass2gaus}
pdflatex Lifetime_fitParameter.tex
pdflatex Mass_fitParameter.tex
pdflatex evaluateCtau.tex
#pdflatex evaluateCtau.tex
pdflatex NumEvents.tex
#pdflatex NumEvents.tex
mv Lifetime_fitParameter.pdf PDF/Lifetime_fitParameter.pdf
mv Mass_fitParameter.pdf PDF/Mass_fitParameter.pdf
mv evaluateCtau.pdf PDF/evaluateCtau.pdf
mv NumEvents.pdf PDF/NumEvents.pdf
fi

if [ ${execute_runBkgHistos} -eq 1 ]
then
cp runBkgHistos runBkgHistos_$[nState-3]S_rap${rapMin}_pt${ptMin}_cpm${cpmMin}
./runBkgHistos_$[nState-3]S_rap${rapMin}_pt${ptMin}_cpm${cpmMin} rapMin=${rapMin} rapMax=${rapMax} ptMin=${ptMin} ptMax=${ptMax} cpmMin=${cpmMin} cpmMax=${cpmMax} nState=${nState} MC=${MC} doCtauUncer=${doCtauUncer} PolLSB=${PolLSB} PolRSB=${PolRSB} PolNP=${PolNP} ctauScen=${ctauScen} FracLSB=${FracLSB} forceBinning=${forceBinning} folding=${folding} normApproach=${normApproach} scaleFracBg=${scaleFracBg} ${polDataPath}=polDataPath fitmass2gaus=${fitmass2gaus}
rm runBkgHistos_$[nState-3]S_rap${rapMin}_pt${ptMin}_cpm${cpmMin}
fi

if [ ${execute_PlotCosThetaPhiBG} -eq 1 ]
then
./PlotCosThetaPhiBG nState=${nState}
pdflatex cosThetaPhi_$[nState-3]S_BG.tex
pdflatex cosThetaPhi_$[nState-3]S_BG_highct.tex
pdflatex cosThetaPhi_$[nState-3]S_NPBG.tex
pdflatex cosThetaPhi_$[nState-3]S_TBG.tex
pdflatex NumEventsFracBG_Psi$[nState-3]S.tex
pdflatex meanPt_Psi$[nState-3]S.tex
mv cosThetaPhi_$[nState-3]S_BG.pdf PDF/cosThetaPhi_$[nState-3]S_BG.pdf
mv cosThetaPhi_$[nState-3]S_BG_highct.pdf PDF/cosThetaPhi_$[nState-3]S_BG_highct.pdf
mv cosThetaPhi_$[nState-3]S_NPBG.pdf PDF/cosThetaPhi_$[nState-3]S_NPBG.pdf
mv cosThetaPhi_$[nState-3]S_TBG.pdf PDF/cosThetaPhi_$[nState-3]S_TBG.pdf
mv NumEventsFracBG_Psi$[nState-3]S.pdf PDF/NumEventsFracBG_Psi$[nState-3]S.pdf
mv meanPt_Psi$[nState-3]S.pdf PDF/meanPt_Psi$[nState-3]S.pdf
fi

if [ ${execute_PlotCosThetaPhiDistribution} -eq 1 ]
then
./PlotCosThetaPhiDistribution ${nState}nState ${WorkDir}=DataPath
pdflatex cosThetaPhi_$[nState-3]S.tex
mv cosThetaPhi_$[nState-3]S.pdf PDF/cosThetaPhi_$[nState-3]S.pdf
fi

#rm runData
#rm runWorkspace
#rm runMassFit
#rm runLifetimeFit
#rm runPlotMassLifetime
#rm runBkgHistos
#rm PlotFitPar
#rm PlotCosThetaPhiBG
#rm PlotCosThetaPhiDistribution
#rm *.tex
rm *.aux
rm *.log
rm *.so
rm *.d
rm *.nav 
rm *.out 
rm *.snm 
rm *.toc 

done
done

