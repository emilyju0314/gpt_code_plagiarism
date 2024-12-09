void
GenParticleCounter::beginJob()
{

  theTree  = fs->make<TTree>("photon","Tree of Rechits around photon");

  theTree->Branch("nPar",&nPar,"nPar/I");
  theTree->Branch("recoVtxZ",&recoVtxZ,"recoVtxZ/F");

  theTree->Branch("et",et,"et[nPar]/F");
  theTree->Branch("eta",eta,"eta[nPar]/F");
  theTree->Branch("phi",phi,"phi[nPar]/F");
  theTree->Branch("id",id,"id[nPar]/I");
  theTree->Branch("momId",momId,"momId[nPar]/I");
  theTree->Branch("status",status,"status[nPar]/I");
  theTree->Branch("collId",collId,"collId[nPar]/I");

  std::cout<<"done beginjob"<<std::endl;
}