/*
 * This example demostrates how to make thick 
 * markers on plots by stacking several graphs
 * and vary their marker sizes.
 */
void thick_marker(){
    gStyle->SetLineWidth(3.0);
    gStyle->SetFrameLineWidth(3.0);
    float x[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    float xe[9] = {.5, .5, .5, .5, .5, .5, .5, .5, .5};
    float y[9] = {0.4, 0.6, 0.4, 0.9, 0.7, 0.2, 1.2, 1.4, 1.9};
    float ye[9] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
    TGraphErrors* gerr = new TGraphErrors(9, x, y, 0, ye);
    gerr->SetMarkerStyle(24);
    gerr->SetMarkerSize(2. * gerr->GetMarkerSize());
    gerr->SetMarkerColor(2);
    gerr->Draw("Ap");

    TGraphErrors* gerr1 = (TGraphErrors*)gerr->Clone();
    gerr1->SetMarkerSize(0.9 * gerr->GetMarkerSize());
    gerr1->Draw("p same");

    // Legend
    float xx[1] = {0.6};
    float xxe[1] = {0.1};
    float yy[1] = {.7};
    float yye[1] = {.1}; 
    TGraphErrors* gerr2 = new TGraphErrors(1, xx, xxe, yy, yye);
    gerr2->SetMarkerStyle(24);
    gerr2->SetMarkerColor(2);
    gerr2->SetMarkerSize(gerr->GetMarkerSize());
    gerr2->Draw("p same");

    TGraphErrors* gerr3 = (TGraphErrors*)gerr2->Clone();
    gerr3->SetMarkerSize(0.9 * gerr->GetMarkerSize());
    gerr3->Draw("p same");

    gerr->SetMarkerSize(gerr->GetMarkerSize());
    TLegend* leg = new TLegend(0.5, 0.6, 0.8, 0.9);
    leg->AddEntry(gerr, "gerr", "pl");
    leg->AddEntry(gerr, "gerr", "pl");
    leg->AddEntry(gerr, "gerr", "pl");
    leg->AddEntry(gerr, "gerr", "pl");
    leg->Draw("same");
}
