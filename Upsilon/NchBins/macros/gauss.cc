using namespace std;

#include "TROOT.h"

#include "gauss.C"

int main()
{
    gROOT->ProcessLine(".L gauss.C+");

  return 0;
}