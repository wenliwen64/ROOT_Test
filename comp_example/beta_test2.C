{
    //TFile* file = new TFile("test.omega.picodst.root", "read");
    TFile* file = new TFile("newtest.omega.picodst.root", "read");
    //TTree* tree = (TTree*)file->Get("XiPicoDst");
    TTree* tree = (TTree*)file->Get("XiPicoDst");
    int nentries = tree->GetEntries();
    for(int i = 0; i < nentries; i++){
        tree->GetEntry(i);
        TLeaf* leaf_nproton = tree->GetLeaf("nproton");
	TLeaf* leaf_protonbeta = tree->GetLeaf("protonbeta"); 
	TLeaf* leaf_protontof = tree->GetLeaf("protontof");
        TLeaf* leaf_protonnsigma = tree->GetLeaf("protonnsigma");
	TLeaf* leaf_protonpathlen = tree->GetLeaf("protonpathlen");
        TLeaf* leaf_protondca = tree->GetLeaf("protondcaglobal");

        int nproton = leaf_nproton->GetValue(0);
        //int ntrks = leaf_ntrks->GetValue(0);
        for(int j = 0; j < nproton; j++){
            float tof = leaf_protontof->GetValue(j);
            float pathlen = leaf_protonpathlen->GetValue(j);
            float nsigma_p = leaf_protonnsigma->GetValue(j);
            float protondca = leaf_protondca->GetValue(j);
            //float tof = leaf_tof->GetValue(j);
            //float pathlen = leaf_pathlen->GetValue(j);
            if(tof < 0) continue;
            if(abs(nsigma_p) < 2.0) continue;  
            float beta = leaf_protonbeta->GetValue(j);
            cout << beta << " = beta <-----> " << pathlen/tof/29.9792458 << " = computation" << " <----dca---->" << protondca << endl;
            //cout << "<-----> " << pathlen/tof << " = computation" << endl;
	}
    }
}
