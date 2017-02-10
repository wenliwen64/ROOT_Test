{
  TCanvas *c1 = new TCanvas("c1","Profile histogram example",200,10,700,500);
  hprof2d  = new TProfile2D("hprof2d","Profile of pz versus px and py",10,-4,4,10,-4,4,0,20);
  Float_t px, py, pz;
    for ( Int_t i=0; i<25000; i++) {
     gRandom->Rannor(px,py);
     pz = px*px + py*py;
     hprof2d->Fill(px,py,pz,1);
    }
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);
  hprof2d->SetContour(10);
  hprof2d->Draw("COLZ");
  hprof2d->Draw("TEXT SAME");
}
