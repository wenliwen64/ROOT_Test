/*
 * This example shows how the mT and pT relates 
 * to each other.
 */
#include "../CVE_project/util/RtPlotTempFactory.h"
#include "../CVE_project/util/RtStyleFactory.h"
using namespace rtplot;
void mT(){
    RtStyle* style = RtStyleFactory::instance()->createStyle("gamma");
    style->setXMin(0);
    style->setXMax(2.0);
    style->setYMax(2.0);
    style->setYMin(0.0);
    style->setYTitle("m_{T}(GeV/c^{2})");
    style->setXTitle("p_{T}(GeV/c)");
    style->setXLabelSize(style->getYLabelSize());
    RtPlotTempFactory::instance()->setGStyle(style);

    TCanvas* c = RtPlotTempFactory::instance()->getCanvas("c0", style);
    TH2F* h2f = RtPlotTempFactory::instance()->getBgPad(style);
    h2f->Draw();

    TF1* f = new TF1("f2", "sqrt(1.0 * 1.0 + x * x) - 1.0", 0, 2.0);
    f->SetLineStyle(8);
    f->SetLineWidth(5);
    f->SetLineColorAlpha(kRed, .6);
    f->Draw("same");

    TF1* f1 = new TF1("f1", "x", 0, 2.0);
    f1->SetLineStyle(8);
    f1->SetLineWidth(5);
    f1->SetLineColorAlpha(kBlue, .6);
    f1->Draw("same");
}
