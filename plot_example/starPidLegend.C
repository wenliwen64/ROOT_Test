{
    double x[3] = {.1, .2, .3};
    double y[3] = {.1, .2, .3};

    TGraph* g = new TGraph(3, x, y);
    g->SetLineStyle(1);
    g->SetLineWidth(3.0);
    g->SetLineColor(kRed);
    g->Draw("A l");

    TGraph* g1 = new TGraph(3, x, y);
    g1->SetLineStyle(1);
    g1->SetLineWidth(3.0);
    g1->SetLineColor(kGreen);
    g1->Draw("pl");

    TGraph* g2 = new TGraph(3, x, y);
    g2->SetLineStyle(1);
    g2->SetLineWidth(3.0);
    g2->SetLineColor(kBlue);
    g2->Draw("pl");

    TGraph* g3 = new TGraph(3, x, y);
    g3->SetLineStyle(3);
    g3->SetLineWidth(3.0);
    g3->SetLineColor(kRed);
    g3->Draw("pl");

    TLegend* leg = new TLegend(.5, .5, .8, .8);
    leg->SetBorderSize(0);
    leg->AddEntry(g, "#pi^{-}", "l");
    leg->AddEntry(g1, "K^{-}", "l");
    leg->AddEntry(g2, "#bar{p}", "l");
    leg->AddEntry(g3, "fit", "l");
    leg->Draw();
}
