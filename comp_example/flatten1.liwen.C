#include <TRandom3.h>
#include <iostream>
#include <TH1F.h>
#include <TCanvas.h>
#include <TProfile.h>
void flatten1()
{
    TRandom3 r1(0);
    const int num = 1000000;
    double v2=0.05;
    double xxx[num];
    double choose[num];
    TProfile* source0=new TProfile("source0","source hist",50,0.5,50.5,-1.1,1.1);
    TProfile* source1=new TProfile("source1","source1 hist",50,0.5,50.5,-1.1,1.1);
    TH1F *final1=new TH1F("final1","final1 his",1000,0,2*3.1415926);
    int count = 0;
    while(count < num){
	xxx[count]=2*3.1415926*r1.Rndm();
	choose[count]=0;
	//double z=3.1415926*gRandom->Rndm();
	double ypositive=(r1.Rndm())*(1+2*v2);
	if(ypositive >1+2*v2*cos(2*(xxx[count])))
	{continue;
	} 
	else{
	    //final1->Fill(xxx[count]);
	    count = count + 1;
	} 
    }

    const int cornum = 40;
    for(int u=0; u<num; u++)
    {
	if(xxx[u]<1||xxx[u]>1.5){
	    final1->Fill(xxx[u]);
	    for(int n=0; n<cornum; n++){
		source0->Fill(n+1, sin((n+1)*xxx[u]), 1);
		source1->Fill(n+1, cos((n+1)*xxx[u]), 1);
		choose[u] = 1;
	    }
	}
	else{double random=r1.Rndm();
	    if(random>0.2)
	    {
		final1->Fill(xxx[u]);
		for(int n=0;n<cornum;n++)
		{
		    source0->Fill(n+1, sin((n+1)*xxx[u]), 1);
		    source1->Fill(n+1, cos((n+1)*xxx[u]), 1);
		    choose[u] = 1;
		}
	    }
	}
    }

    TCanvas* c0 = new TCanvas("c0", "c0");
    final1->Draw();
    double xx[cornum],yy[cornum];
    for(int q = 0; q < cornum; q++)
    {
	xx[q] = source0->GetBinContent(q+1);
	yy[q] = source1->GetBinContent(q+1);
	cout << "sin = " << xx[q] << endl;
	cout << "cos = " << yy[q] << endl;
    }
    TCanvas *c1=new TCanvas("c1","c1",400,500);
    TH1F *final=new TH1F("final","final his", 1000, 0, 2*3.1415926);

    for(int t = 0;t < num;t++)
    {
	double addterm=0;
	for(int p=0;p<cornum;p++)
	{
	    {
		addterm=addterm+((double)2/(p+1)) * (-xx[p]*cos((p+1)*xxx[t])+yy[p]*sin((p+1)*xxx[t]));
	    }
	}


	xxx[t]=xxx[t]+addterm;
	while(xxx[t]>2*3.1415926){
	  xxx[t]=xxx[t]-2*3.1415926;
	  }
	while(xxx[t]<0){
	  xxx[t]=xxx[t]+2*3.1415926;
	}
	if(choose[t]==1)
	{final->Fill(xxx[t]);
	}	
    }
    TCanvas* c2 = new TCanvas();
    final->Draw();
}

