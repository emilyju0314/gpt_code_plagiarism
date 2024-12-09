void
L1UpgradeFlatTreeProducer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  
  l1Upgrade->Reset();

  edm::Handle<l1t::EGammaBxCollection> eg;
  edm::Handle<l1t::JetBxCollection> jet;
  edm::Handle<l1t::EtSumBxCollection> sums;
  edm::Handle<l1t::MuonBxCollection> muon; 

  if (doEg_) iEvent.getByToken(egToken_,   eg);
  if (doJet_) iEvent.getByToken(jetToken_,  jet);
  if (doSum_) iEvent.getByToken(sumToken_, sums);
  if (doMuon_) iEvent.getByToken(muonToken_, muon);

  if (doEg_) {
    if (eg.isValid()){ 
      l1Upgrade->SetEm(eg, maxL1Upgrade_);
    } else {
      edm::LogWarning("MissingProduct") << "L1Upgrade Em not found. Branch will not be filled" << std::endl;
    }
  }

  if (doJet_) {
    if (jet.isValid()){ 
      l1Upgrade->SetJet(jet, maxL1Upgrade_);
    } else {
      edm::LogWarning("MissingProduct") << "L1Upgrade Jets not found. Branch will not be filled" << std::endl;
    }
  }

  if (doSum_) {
    if (sums.isValid()){ 
      l1Upgrade->SetSum(sums, maxL1Upgrade_);  
    } else {
      edm::LogWarning("MissingProduct") << "L1Upgrade EtSums not found. Branch will not be filled" << std::endl;
    }
  }

  if (doMuon_) {
    if (muon.isValid()){ 
      l1Upgrade->SetMuon(muon, maxL1Upgrade_);
    } else {
      edm::LogWarning("MissingProduct") << "L1Upgrade Muons not found. Branch will not be filled" << std::endl;
    }
  }

  if (doTau_) {
    for (auto & tautoken: tauTokens_){
      edm::Handle<l1t::TauBxCollection> tau;
      iEvent.getByToken(tautoken,  tau);
      if (tau.isValid()){ 
        l1Upgrade->SetTau(tau, maxL1Upgrade_);
      } else {
        edm::LogWarning("MissingProduct") << "L1Upgrade Tau not found. Branch will not be filled" << std::endl;
      }
    }
  }

  tree_->Fill();

}