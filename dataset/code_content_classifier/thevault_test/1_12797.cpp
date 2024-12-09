void
METAnalyzer::beginJob()
{

  metTree_ = fs->make<TTree>("metTree","v1");

  // event
  metTree_->Branch("nEv",&pev_.nEv,"nEv/I");
  metTree_->Branch("nLumi",&pev_.nLumi,"nLumi/I");
  metTree_->Branch("nBX",&pev_.nBX,"nBX/I");
  metTree_->Branch("nRun",&pev_.nRun,"nRun/I");

  metTree_->Branch("nMET",&pev_.nMET,"nMET/I");
  metTree_->Branch("MET",pev_.METEt,"MET[nMET]/F");
  metTree_->Branch("METPhi",pev_.METPhi,"METPhi[nMET]/F");
  metTree_->Branch("SumEt",pev_.METSumEt,"SumEt[nMET]/F");
  //
}