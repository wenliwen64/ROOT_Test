{
    int reverseAxis = 1;
    int canvasWidth = 700, canvasHeight = 500; // landscape
    TCanvas* cc = new TCanvas("c1", "", canvasWidth, canvasHeight);

    TString* histGraphName = new TString("Flow_v1");
    TH1F* histGraph = new TH1F(histGraphName->Data(), "", 24, 0, 80);
    histGraph->SetMaximum(0.9);
    histGraph->SetMinimum(0.3);
    histGraph->SetLineColor(kBlack);
    histGraph->SetXTitle("% Most Central");
    histGraph->SetYTitle("EP Resolution");
    histGraph->GetYaxis()->SetTitleOffset(.7);
    histGraph->GetYaxis()->SetTitleSize(0.055);
    histGraph->GetXaxis()->SetTitleSize(0.055);
    histGraph->GetXaxis()->SetTitleOffset(.7);
    histGraph->GetXaxis()->SetNdivisions(505);
    histGraph->SetTitle("Event Plane Resolution v.s. Centrality");
    if (reverseAxis==1){
	double lsize=histGraph->GetLabelSize();
	histGraph->SetLabelSize(0.,"X");
    }
    histGraph->Draw();

    if(reverseAxis==1){
	double ymin = -0.0012;
	TF1 *f1 = new TF1("f1", "80.-x", 0., 80);
	TGaxis *A1 = new TGaxis(0., ymin, xScale, ymin, "f1", 510, "+");
	A1->SetLabelSize(lsize);
	A1->SetLineColor(1);
	A1->Draw();
    }

    Double_t cent[9] = {75,65,55,45,35,25,15,7.5,2.5};
    Double_t resol[9] = {.2121, .3104, .4285, .5397, .6214, .6550, .6197, .5192, .4137};
    TGraphErrors* gerr = new TGraphErrors(9, cent, resol, 0, 0);
    gerr->SetMarkerStyle(30);
    gerr->SetMarkerSize(1.5);
    gerr->SetMarkerColor(2);
    gerr->Draw("pe same");
    //gPad->SetTicks(1, 1);
}
