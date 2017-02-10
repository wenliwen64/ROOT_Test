{
    //TFile* file = new TFile("test.omega.picodst.root", "read");
    TFile* file = new TFile("test.lambda.picodst.root", "read");
    //TTree* tree = (TTree*)file->Get("XiPicoDst");
    TTree* tree = (TTree*)file->Get("StrangenessDst");
    int nentries = tree->GetEntries();
    for(int i = 0; i < nentries; i++){
        tree->GetEntry(i);
        //TLeaf* leaf_nproton = tree->GetLeaf("nproton");
	//TLeaf* leaf_protonbeta = tree->GetLeaf("protonbeta"); 
	//TLeaf* leaf_protontof = tree->GetLeaf("protontof");
        //TLeaf* leaf_protonnsigma = tree->GetLeaf("protonnsigma");
	//TLeaf* leaf_protonpathlen = tree->GetLeaf("protonpathlen");
        //TLeaf* leaf_protondca = tree->GetLeaf("protondcaglobal");
        TLeaf* leaf_pathlen = tree->GetLeaf("fV0s.mPathlenV0");
        TLeaf* leaf_tof = tree->GetLeaf("fV0s.mTofV0");
        TLeaf* leaf_ntrks = tree->GetLeaf("mNoTracks");

        //int nproton = leaf_nproton->GetValue(0);
        int ntrks = leaf_ntrks->GetValue(0);
        for(int j = 0; j < ntrks; j++){
            //float tof = leaf_protontof->GetValue(j);
            //float pathlen = leaf_protonpathlen->GetValue(j);
            //float nsigma_p = leaf_protonnsigma->GetValue(j);
            //float protondca = leaf_protondca->GetValue(j);
            float tof = leaf_tof->GetValue(j);
            float pathlen = leaf_pathlen->GetValue(j);
            if(tof < 0) continue;
            //if(abs(nsigma_p) < 2.0) continue;  
            //float beta = leaf_protonbeta->GetValue(j);
            //cout << beta*299792458 << " = beta <-----> " << pathlen/tof << " = computation" << " <----dca---->" << protondca << endl;
            cout << "<-----> " << pathlen/tof << " = computation" << endl;
	}
    }
}
