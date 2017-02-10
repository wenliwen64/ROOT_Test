#include "../CVE_project/util/RtStyleFactory.h"
#include "../CVE_project/util/RtPlotTempFactory.h"
using namespace rtplot;
void doubleGaussian(){
    RtPlotTempFactory::instance()->
    RtStyleFactory::instance()->set
    TF2* f2 = new TF2("f2", "[0]*TMath::Gaus(0.5*x+3^0.5/2*y, [1], [2])*TMath::Gaus(-3^0.5/2*x+0.5*y, [3], [4])", -10, 10, -10, 10);
    f2->SetParameters(1, 3, 1, 4, 2);
    //f2 -> FillRandom("f2", 100000);
    //f2 -> Draw("surf1z");
    f2->Draw("colorz");

    TCanvas* c2 = new TCanvas("c2");
    TF2 *f3 = new TF2("f3","[0]*TMath::Gaus(x,[1],[2])*TMath::Gaus(y,[3],[4])", -10,10, -10,10);
    f3->SetParameters(1,3,1,4,2);
    f3->Draw("colorz");

//Fill 2D Histogram
    TCanvas* c3 = new TCanvas("c3");
    TH2F* h2 = new TH2F("h2", "h2", 100, -10, 10, 100, -10, 10); 
    for(int i = 0; i < 100000; i++){
        double x, y;
        f3->GetRandom2(x, y);
        h2->Fill(x, y);
    }
    int xminbin = h2->GetXaxis()->FindBin(0.);
    int xmaxbin = h2->GetXaxis()->FindBin(6.);
    int yminbin = h2->GetYaxis()->FindBin(0.);
    int ymaxbin = h2->GetYaxis()->FindBin(8.);
    cout << xminbin << " " << xmaxbin << " " << yminbin << " " << ymaxbin << endl;
    int core_counts = h2->Integral(xminbin,xmaxbin,yminbin,ymaxbin);
    std::cout<<"total counts inside box ======> "<<core_counts<<std::endl;
    h2->Draw("colz");
}
