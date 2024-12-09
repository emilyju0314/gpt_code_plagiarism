void
FastJetAnalyzer::beginJob()
{

  for(unsigned int ialgo = 0; ialgo < labels_.size(); ++ialgo){
    MyBkg b;
    bkgs_.push_back(b);
    trees_.push_back(fs->make<TTree>(Form("%s",labels_[ialgo].data()),""));
    trees_[ialgo]->Branch("n",&bkgs_[ialgo].n,"n/I");
    trees_[ialgo]->Branch("rho",bkgs_[ialgo].rho,"rho[n]/F");
    trees_[ialgo]->Branch("sigma",bkgs_[ialgo].sigma,"sigma[n]/F");
  }

}