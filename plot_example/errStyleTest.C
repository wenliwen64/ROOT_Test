/*
 * This example shows different styles of errors 
 */
#include "../CVE_project/util/RtPlotTempFactory.h"
#include "../CVE_project/util/RtStyleFactory.h"
using namespace rtplot;
void errStyleTest(){
    RtStyleFactory* styleFactory = RtStyleFactory::instance();
    RtStyle* style = styleFactory->createStyle("gamma");
    RtPlotTempFactory* tempFactory = RtPlotTempFactory::instance();
    style->setYMin(-1.0);
    style->setYMax(8.2);
    style->setXMin(-4.0);
    style->setXMax(4.0);

    tempFactory->setGStyle(style);

    TCanvas* can = tempFactory->getCanvas("c1", style);
    TH2F* bg = tempFactory->getBgPad(style);
    bg->Draw();

    // Data
    double x[5] = {-3.0, -1.5, 0.0, 1.5, 3.0};
    double xerr[5] = {1.0, 1.0, 1.0, 1.0, 1.0};
    double y[5] = {0, .5, 1.0, .5, 0.0};
    double y1[5] = {-.3, .2, .7, .2, -.3};
    double y2[5] = {.3, .7, 1.1, .7, .3};
    double y3[5] = {.7, 1.1, 1.5, 1.1, .7};
    double y4[5] = {1.1, 1.5, 1.9, 1.5, 1.1};
    double y5[5] = {0,};
    double y6[5] = {0,};

    for(int i = 0; i != 5; ++i){
	y1[i] = y[i] + 1.0;
	y2[i] = y[i] + 2.0;
	y3[i] = y[i] + 3.0;
	y4[i] = y[i] + 4.0;
	y5[i] = y[i] + 5.0;
	y6[i] = y[i] + 6.0;
    }
    double yerr[5] = {.3, .3, .3, .3, .3};

    // TGraphErrors
    TGraphErrors* gerr0 = new TGraphErrors(5, x, y, xerr, yerr);
    gerr0->SetMarkerStyle(kFullCircle);
    gerr0->SetMarkerColorAlpha(kRed, 0.5);
    gerr0->SetLineColor(1);
    gerr0->Draw("p>");

    TGraph* gerr0_shell = tempFactory->getShellG(gerr0, kOpenCircle);
    gerr0_shell->Draw("p"); 

    TGraphErrors* gerr1 = new TGraphErrors(5, x, y1, xerr, yerr);
    gerr1->SetMarkerStyle(kFullCircle);
    gerr1->SetMarkerColorAlpha(kBlue, 0.5);
    gerr1->SetLineColor(1);
    gerr1->Draw("p|>");

    TGraphErrors* gerr2 = new TGraphErrors(5, x, y2, xerr, yerr);
    gerr2->SetMarkerStyle(kFullCircle);
    gerr2->SetMarkerColorAlpha(kBlue, 0.5);
    gerr2->SetLineColor(1);
    gerr2->Draw("|| p");

    TGraphErrors* gerr3 = new TGraphErrors(5, x, y3, xerr, yerr);
    gerr3->SetMarkerStyle(kFullCircle);
    gerr3->SetMarkerColorAlpha(kBlue, 0.5);
    gerr3->SetFillColor(1);
    gerr3->SetFillStyle(0);
    gerr3->SetLineColor(1);
    gerr3->Draw("2 p");

    TGraphErrors* gerr4 = new TGraphErrors(5, x, y4, xerr, yerr);
    gerr4->SetMarkerStyle(kFullCircle);
    gerr4->SetMarkerColorAlpha(kMagenta, 0.5);
    gerr4->SetFillColor(1);
    gerr4->SetFillStyle(0);
    gerr4->SetLineColor(1);
    gerr4->Draw("3 p");

    TGraphErrors* gerr5 = new TGraphErrors(5, x, y5, xerr, yerr);
    gerr5->SetMarkerStyle(kFullCircle);
    gerr5->SetMarkerColorAlpha(kBlack, 0.5);
    gerr5->SetFillColorAlpha(kRed, .6);
    //gerr5->SetFillStyle(0);
    gerr5->SetLineColor(1);
    gerr5->Draw("4 p");

    TGraphErrors* gerr6 = new TGraphErrors(5, x, y6, xerr, yerr);
    gerr6->SetMarkerStyle(kFullCircle);
    gerr6->SetMarkerColorAlpha(kBlack, 0.5);
    gerr6->SetFillColorAlpha(kRed, .6);
    //gerr6->SetFillStyle(0);
    gerr6->SetLineColor(1);
    gerr6->Draw("5 p");

}
