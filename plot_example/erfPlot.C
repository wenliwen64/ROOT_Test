/*
 * This example shows how erf varies with coefficient a
 */
#include "../CVE_project/util/RtStyleFactory.h"
#include "../CVE_project/util/RtPlotTempFactory.h"
using namespace rtplot;
void erfPlot(){
    double xmin = -2;
    double xmax = 2;
    RtStyle* style = RtStyleFactory::instance()->createStyle("gamma");
    style->setXMin(xmin);
    style->setXMax(xmax);
    style->setYMin(-1.);
    style->setYMax(1.);
    style->setYTitle("y");
    style->setXTitle("x");
    style->setXLabelSize(style->getYLabelSize());
    RtPlotTempFactory::instance()->setGStyle(style);

    TCanvas* can = RtPlotTempFactory::instance()->getCanvas("c0", style); 
    TH2F* h2f = RtPlotTempFactory::instance()->getBgPad(style);
    h2f->Draw();

    TLegend* leg = new TLegend(.6, .2, .89, .45);
    leg->SetNColumns(2);

    TF1* erf[5];// = new TF1("f1", "TMath::Erf(x)", 0, 4);
    for(int i = 0; i < 5; i++){
        TString func;
        func.Form("TMath::Erf(%d*x)", i * 2 + 1);
        erf[i] = new TF1("f", func, xmin, xmax); 
	erf[i]->SetLineStyle(9);
	erf[i]->SetLineWidth(5);
        erf[i]->SetLineColorAlpha(i + 1, .6);
	erf[i]->Draw("same");

	char name[50];
	sprintf(name, "a = %d", i * 2 + 1);
	leg->SetTextSize(style->getLegendTextSize());
	leg->AddEntry(erf[i], name, "l");
    } 
    leg->Draw();

    TLatex* text = RtPlotTempFactory::instance()->getDescText(.18, .5, style, "Erf(a * x)");
    text->Draw();
}
