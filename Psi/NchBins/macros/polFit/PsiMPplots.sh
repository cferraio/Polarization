#cp ../../latex/myStyle.tex myStyle.tex
#cp ../../latex/PsiMPplots.tex PsiMPplots.tex
root -b -q 'plotComp_RIGOROSUM_Ups.cc+(2, 0, 0)'
root -b -q 'plotComp_RIGOROSUM_Ups.cc+(0, 2, 0)'
root -b -q 'plotComp_RIGOROSUM_Ups.cc+(2, 0, 1)'
root -b -q 'plotComp_RIGOROSUM_Ups.cc+(0, 2, 1)'
root -b -q 'plotComp_RIGOROSUM_Ups.cc+(2, 0, 2)'
root -b -q 'plotComp_RIGOROSUM_Ups.cc+(0, 2, 2)'
#pdflatex PsiMPplots.tex
rm plotComp_RIGOROSUM_Ups_cc.so
rm plotComp_RIGOROSUM_Ups_cc.d
#rm PsiMPplots.aux
#rm PsiMPplots.log
#rm PsiMPplots.toc
#rm PsiMPplots.nav
#rm PsiMPplots.snm
#rm PsiMPplots.out
#rm myStyle.tex
#rm PsiMPplots.tex
#rm texput.log