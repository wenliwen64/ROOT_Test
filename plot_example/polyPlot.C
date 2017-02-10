void polyPlot(){
    TF1* f1 = new TF1("f1", "(x-1)^2*(x^2+x+1)", -3, 4);
    f1->SetLineStyle(5);
    f1->SetLineColorAlpha(kRed, .6);
    f1->Draw();
}
