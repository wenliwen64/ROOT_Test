{
    TH1F* h1 = new TH1F("h1", "h1", 100, -5., 5.);
    TH1F* h2 = new TH1F("h2", "h2", 100, -5., 5.);// = new TH1F("h2", "h2", 100, -5., 5.);

    TF1* gaus1 = new TF1("gaus1", "exp(-(x-1.)*(x-1.)/2)");
    TCanvas* c1 = new TCanvas("c1", "c1");
    h1->FillRandom("gaus", 1000);
    h2->FillRandom("pol1", 10000);
    //h1->Sumw2();
    //h2->Sumw2();
    int a = h1->GetEntries();
    h1->Draw();
    cout << a << endl;
    //h2 = (TH1F*)h1->Clone();
    //h2->Scale(1./10);
    //a = h1->Integral();
    h2->Add(h1, -1.5);
    a = h2->GetEntries();
    
    int b = h2->Integral();    
    TCanvas* c2 = new TCanvas("c2", "c2");
    h2->Draw("E");
    cout << a << "============" << b << endl;
   
/*
    TFile* fdata = new TFile("/Users/lwen/Documents/Omg_Phi_14GeV/Omega/embedding/analysis/test_hist_embedding_15GeV.root", "read");
    TFile* frot = new TFile("/Users/lwen/Documents/Omg_Phi_14GeV/Omega/embedding/analysis/testrot_hist_embedding_15GeV.root", "read");
    TH1F* hdata;
    TH1F* hrot;
   
    hdata = (TH1F*)fdata->Get("hmDau1nHits_cen1pt5");
    hrot = (TH1F*)frot->Get("hmDau1nHits_cen1pt5");
    int bin = 44;
    cout<<hdata->GetBinError(bin)<<endl;
    hdata->Sumw2();
    cout<<hdata->GetBinError(bin)<<" " <<hrot->GetBinError(bin)<<endl;
    hrot->Sumw2();
    cout<<hdata->GetEntries()<<endl;
    
    TCanvas* c1 = new TCanvas("c1");
    TCanvas* c2 = new TCanvas("c2");
    c1->cd();
    hrot->Draw();
    hdata->Add(hrot, -1./1.03);
    cout<<hdata->GetBinError(bin)<< " " <<hdata->GetBinContent(bin)<<endl;
    c2->cd();
    hrot->Draw();
    cout<<hdata->GetEntries()<<endl;
*/
}
