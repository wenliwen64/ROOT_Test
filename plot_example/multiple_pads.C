{
    gStyle->SetPadBorderMode(0);
    gStyle->SetFrameBorderMode(0);
    gStyle->SetFrameLineWidth(6.0);
    gStyle->SetOptStat(0);
    //Float_t small = 0.1;//1e-12; 
    Float_t small = 1e-12;//1e-12; 
    TCanvas can("c1", "c1", 1600, 600);
    can.Divide(4, 2, 0, 0);
    TH1F* h[8];
    cout << "happy before plotting." << endl;
    for(Int_t i = 0; i < 8; i++){
        Int_t j = 8 - i; 
        char name[100];
        sprintf(name, "h%d", j);
        h[j - 1] = new TH1F(name, "", 100, -5.1, 5.1);
	h[j - 1]->FillRandom("gaus", 10000);
        h[j - 1]->SetMaximum(490);
        h[j - 1]->SetMinimum(-50);
        
        can.cd(j);
        gPad->SetTicks(1,1);
	gPad->SetBorderSize(0.0);
        gPad->SetBottomMargin(small);
        gPad->SetRightMargin(small); 
        gPad->SetTopMargin(small);
        gPad->SetLeftMargin(small);
	TLine* line = new TLine(-5.1, 0, 5.1, 0);
        if(j <= 4){
             gPad->SetTopMargin(1);
	}
        else{
            //gPad->SetLeftMargin(1);
            gPad->SetBottomMargin(1);
            //gPad->SetTickx();
            //gPad->SetTicky();
	}

        if(j == 1 ) {
            gPad->SetLeftMargin(1);
	}
        else if(j == 4 ){
            gPad->SetRightMargin(1);  
        }
        else if(j == 5 ){
            gPad->SetBottomMargin(1);
            gPad->SetLeftMargin(1);
            //gPad->SetTickx();
	}
        else if(j == 8){
            gPad->SetRightMargin(1);
            //gPad->SetTickx();
        }
	h[j - 1]->GetYaxis()->SetNdivisions(3);
	h[j - 1]->GetYaxis()->SetTickSize(1.0);//Ndivisions(3);
        h[j - 1]->Draw();
	line->Draw("same");
	cout << name << endl;
        //gPad->Draw();
    }
}
