/*
 * This example shows 4 iid sum makes a gassian dist.
 */
#include "../CVE_project/util/RtPlotTempFactory.h"
#include "../CVE_project/util/RtStyleFactory.h"
using namespace rtplot;
void nRandom(){
    RtStyle* style = RtStyleFactory::instance()->createStyle("gamma");
    style->setXMin(0);
    style->setXMax(4);
    style->setYMin(0);
    style->setYMax(10000);
    style->setYTitle("# of Entries");
    style->setXTitle("x");
    style->setXLabelSize(style->getYLabelSize());
    RtPlotTempFactory::instance()->setGStyle(style);


    gRandom = new TRandom3();

    TCanvas* can = RtPlotTempFactory::instance()->getCanvas("c0", style);
    TH2F* h2f = RtPlotTempFactory::instance()->getBgPad(style);
    h2f->Draw();

    gStyle->SetOptStat(1);
    gStyle->SetOptFit(1);
    TH1F* h1 = new TH1F("h1", "h1", 400, 0, 4);
    for(int i = 0; i < 1000000; i++){
	float x1 = gRandom->Uniform(1); 
	float x2 = gRandom->Uniform(1);
	float x3 = gRandom->Uniform(1);
	float x4 = gRandom->Uniform(1);

	float sum = x1 + x2 + x3 + x4;
	h1->Fill(sum);
    }
    h1->Draw("same");
    h1->Fit("gaus");
}
