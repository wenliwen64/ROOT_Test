/*
 * This example shows how to doe the Canvas division without
 * leaving any space in between pads. 
 */
#include "../CVE_project/util/RtPlotTempFactory.h"
#include "../CVE_project/util/RtStyleFactory.h"
using namespace rtplot;

void div2()
{
    RtStyle* style = RtStyleFactory::instance()->createStyle("gamma");
    style->setYMax(1.1);
    style->setYMin(-1.1);
    RtPlotTempFactory::instance()->setGStyle(style);

    TCanvas* mCanvas = new TCanvas("kt","kt",500,700);

    mCanvas = RtPlotTempFactory::instance()->getDivCan(mCanvas, 5, 4, style); // 5 rows, 4 columns

    TH2F* mHisto = RtPlotTempFactory::instance()->getBgPad(style);

    for(Int_t i = 1 ; i <= 4 * 5; ++i) {
	mCanvas->cd(i) ;
	gPad->SetTicks(1, 1);
	mHisto->Draw() ;
    }
} 
