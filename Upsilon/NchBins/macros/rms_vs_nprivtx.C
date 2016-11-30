c1 = new TCanvas("c1","RMS vs nPriVtx",200,15,700,500);
Int_t n = 7;
Double_t x[n]  = (2.,5.,7.,9.,11.,13.,17.);
Double_t y[n]  = (13.52, 13.45, 13.47, 13.53, 13.51, 13.52, 13.59);
Double_t ex[n] = (0.,0.,0.,0.,0.,0.,0.);
Double_t ey[n] = (2.,1.,1.,1.,1.,1.,3.);
TGraph *gr = new TGraph(n,x,y);
gr->SetTitle("RMS of N_{ch} distro vs nPriVtx Bins");
gr->GetXaxis()->SetTitle("Primary Vertices");
gr->GetYaxis()->SetTitle("RMS");
gr->SetFillColor(kCyan-9);
gr->SetFillStyle(3001);
char drawGraphStyle[200];
sprintf(drawGraphStyle,"PE");
gr->Draw("AP");
c1->Update();



   
   TCanvas *c1 = new TCanvas("c1","gerrors2",200,10,700,500);


      // draw a frame to define the range
   TH1F *hr = c1->DrawFrame(-0.0,13,21,14);
   hr->SetXTitle("Primary Vertices");
   hr->SetYTitle("RMS");


      // create first graph
   const Int_t n1 = 7;
   Double_t x1[]  = {2.0, 5.0, 7.0,9.0,11.0,13.0,17.0};
   Double_t y1[]  = {13.52, 13.45, 13.47, 13.53, 13.51, 13.52, 13.59};
   Double_t ex1[] = {2.,1.,1.,1.,1.,1.,3.};
   Double_t ey1[] = {.0,.0,.0,.0,.0,.0,.0};
   TGraphErrors *gr1 = new TGraphErrors(n1,x1,y1,ex1,ey1);
   gr1->SetMarkerColor(kBlue);
   gr1->SetMarkerStyle(21);
   gr1->Draw("P");
