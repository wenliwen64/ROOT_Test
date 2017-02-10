#include "../CVE_project/util/RtPlotTempFactory.h"
#include "../CVE_project/util/RtStyleFactory.h"
#include <memory>
using namespace std;
using namespace rtplot;
int TLegend_test(){
    RtStyle* style = RtStyleFactory::instance()->createStyle("gamma");
    RtPlotTempFactory::instance()->setGStyle(style);

    //shared_ptr<TH2F> h2d = RtPlotTempFactory::instance()->getBgPad(style);
    TH2F* h2d = RtPlotTempFactory::instance()->getBgPad(style);
    h2d->Draw("");


    float x[5] = {10, 20, 30, 40, 50};
    float y[5] = {-.05, -.1, 0, .05, .1};
    TGraphErrors* gerr = new TGraphErrors(5, x, y, 0, 0);
    gerr->SetMarkerStyle(kFullCircle);
    gerr->SetMarkerColorAlpha(kRed, .5);
    gerr->Draw("pl");

    TGraphErrors* gerr1 = new TGraphErrors(5, x, y, 0, 0);
    gerr1->SetMarkerStyle(kOpenCircle);
    gerr1->SetMarkerSize(style->getMarkerSize() * 1.1);
    gerr1->SetMarkerColor(1);
    gerr1->Draw("pl");

    TLegend* leg1 = new TLegend(.7, .7, .85, .85);
    leg1->SetFillStyle(0);
    leg1->SetBorderSize(0);
    leg1->AddEntry(gerr, " ", "p");
    leg1->Draw();

    TLegend* leg2 = new TLegend(.7, .7, .85, .85);
    leg2->SetFillStyle(0);
    leg2->SetBorderSize(0);
    leg2->AddEntry(gerr1, "test", "p");
    leg2->Draw();

    return 0;
}
