{
TF1* levy = new TF1("levy","2*3.1415926*x*[0]*pow(1+(sqrt(x*x+1.67245*1.67245)-1.67245)/([1]*[2]),-[1])*([1]-1)*([1]-2)/(2*3.14159265*[1]*[2]*([1]*[2]+1.67245*([1]-2)))",0.,8.);
ifstream levy_par("/Users/lwen/Documents/Omg_Phi_14GeV/Omega/plot_scripts/levy_par.dat");
double par0_010, par1_010, par2_010;
double par0_1060, par1_1060, par2_1060;
double dummy = 0.;
levy_par >> dummy >> par0_1060 >> par1_1060 >> par2_1060;
levy_par >> dummy >> par0_010 >> par1_010 >> par2_010;
cout << par0_010 << par1_010 << par2_010 << endl;
levy->SetParameter(0, par0_010);
levy->SetParameter(1, par1_010);
levy->SetParameter(2, par2_010);

cout << "010 yield" << levy.Integral(0, 4.0) << endl; //+ levy.Integral(3.6, 10000) << std::endl;
}
