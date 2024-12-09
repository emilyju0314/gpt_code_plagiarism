void 
HiFJRhoAnalyzer::beginJob()
{

  TString jetTagTitle = "HiFJRho Jet background analysis tree";
  tree_ = fs_->make<TTree>("t",jetTagTitle.Data());
  
  tree_->Branch("etaMin",&(rhoObj_.etaMin));
  tree_->Branch("etaMax",&(rhoObj_.etaMax));
  tree_->Branch("rho",&(rhoObj_.rho));
  tree_->Branch("rhom",&(rhoObj_.rhom));
  tree_->Branch("rhoCorr",&(rhoObj_.rhoCorr));
  tree_->Branch("rhomCorr",&(rhoObj_.rhomCorr));
  tree_->Branch("rhoCorr1Bin",&(rhoObj_.rhoCorr1Bin));
  tree_->Branch("rhomCorr1Bin",&(rhoObj_.rhomCorr1Bin));
  tree_->Branch("rhoGrid",&(rhoObj_.rhoGrid));
  tree_->Branch("meanRhoGrid",&(rhoObj_.meanRhoGrid));
  tree_->Branch("etaMinRhoGrid",&(rhoObj_.etaMinRhoGrid));
  tree_->Branch("etaMaxRhoGrid",&(rhoObj_.etaMaxRhoGrid));
  tree_->Branch("ptJets",&(rhoObj_.ptJets));
  tree_->Branch("etaJets",&(rhoObj_.etaJets));
  tree_->Branch("areaJets",&(rhoObj_.areaJets));
  if (useModulatedRho_) {
    tree_->Branch("rhoFlowFitParams",&(rhoObj_.rhoFlowFitParams));
    tree_->Branch("nTow",&(rhoObj_.nTow));
    tree_->Branch("towExcludePt",&(rhoObj_.towExcludePt));
    tree_->Branch("towExcludePhi",&(rhoObj_.towExcludePhi));
    tree_->Branch("towExcludeEta",&(rhoObj_.towExcludeEta));
  }
}