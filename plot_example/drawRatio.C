/*
 * This example shows how to plot scaled ratio plot using
 * rtplot Library 
 */
#include "../CVE_project/util/RtPlotTempFactory.h"
#include "../CVE_project/util/RtStyleFactory.h"
using namespace rtplot;
void drawRatio(){
    RtStyle* style = RtStyleFactory::instance()->createStyle("gamma");
    RtPlotTempFactory::setGStyle(style);
    RtStyle* style_ratio = RtStyleFactory::instance()->createStyle("gamma");
    style->setYMin(-1.3);
    style->setYMax(1.3);
    style_ratio->setYMin(-2.4);
    style_ratio->setYMax(2.4);

    RtPlotTempFactory* tempFactory = RtPlotTempFactory::instance();
    TCanvas* can = tempFactory->getRatioCanvas("c1");

    TH2F* h = tempFactory->getBgPad(style);
    TPad* p1 = (TPad*)can->GetPrimitive("p1");
    p1->cd();
    h->Draw();

    double ratio_low = p1->GetYlowNDC();
    double ratio_high = 1. - ratio_low;
    style_ratio->setYTitleOffset(style->getYTitleOffset() * ratio_low / ratio_high);
    style_ratio->setXTitleOffset(1.5 * style->getXTitleOffset() * ratio_low / ratio_high);
    style_ratio->setYLabelSize(style->getYLabelSize() * ratio_high / ratio_low);
    style_ratio->setYTitleSize(style->getYTitleSize() * ratio_high / ratio_low);
    style_ratio->setXTitleSize(styl5->getXTitleSize() * ratio_high / ratio_low);
    TH2F* h_ratio = tempFactory->getBgPad(style_ratio);
    TPad* p2 = (TPad*)can->GetPrimitive("p2");
    p2->cd();
    h_ratio->Draw();
}
