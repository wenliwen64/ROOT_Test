void drawInLoop(){
    double x[5] = {1, 2, 3, 4, 5};
    double y[2][5] = {{1, 2, 3, 4, 5}, {2, 4, 6, 8, 10}};
    double yerror[2][5] = {{.1, .1, .1, .1, .1}, {.2, .2, .2, .2, .2}};
    TLegend* leg = new TLegend(0.65, 0.65, 0.85, 0.85);
    for(int i = 0; i < 2; i++){
        TGraphErrors* gerr = new TGraphErrors(5, x, y[i], 0, yerror[i]); 
	gerr->SetMarkerSize(2.0);
        gerr->SetMarkerStyle(24);
        gerr->SetMarkerColor(i+1);
	TGraphErrors* gerr_clone = (TGraphErrors*)gerr->Clone();
	TGraphErrors* gerr_clone1 = (TGraphErrors*)gerr->Clone();
	gerr_clone->SetMarkerSize(0.8 * gerr->GetMarkerSize());
	gerr_clone1->SetMarkerSize(0.9 * gerr->GetMarkerSize());
        //gerr->SetMaximum(0.1);
        //gerr->SetMinimum(0.0);
        //gerr->GetXaxis()->SetLimits(0.5, 3.6);
        if(i == 0){
            gerr->SetTitle("#Omega^{-} Spectra, Au+Au 14.5GeV");     
            gerr->GetYaxis()->SetTitle("efficiency");
            gerr->GetXaxis()->SetTitle("P_{T}(GeV/c)");
            gerr->Draw("AP");
        }
        else{
            gerr->Draw("P same");
        }
	gerr_clone->Draw("P same");
	gerr_clone1->Draw("P same");
        leg->AddEntry(gerr, "happy", "p");
    }
    leg->Draw("sames");
}
