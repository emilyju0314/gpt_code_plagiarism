void HiFJRhoAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;

  //clear vectors
  rhoObj_.etaMin.clear();
  rhoObj_.etaMax.clear();
  rhoObj_.rho.clear();
  rhoObj_.rhom.clear();
  rhoObj_.rhoCorr.clear();
  rhoObj_.rhomCorr.clear();
  rhoObj_.rhoCorr1Bin.clear();
  rhoObj_.rhomCorr1Bin.clear();
  
  rhoObj_.rhoGrid.clear();
  rhoObj_.meanRhoGrid.clear();
  rhoObj_.etaMinRhoGrid.clear();
  rhoObj_.etaMaxRhoGrid.clear();
  
  rhoObj_.ptJets.clear();
  rhoObj_.areaJets.clear();
  rhoObj_.etaJets.clear();

  rhoObj_.rhoFlowFitParams.clear();
  rhoObj_.nTow.clear();
  rhoObj_.towExcludePt.clear();
  rhoObj_.towExcludePhi.clear();
  rhoObj_.towExcludeEta.clear();
  
  // Get the vector of background densities
  edm::Handle<std::vector<double>> etaRanges;
  edm::Handle<std::vector<double>> rho;
  edm::Handle<std::vector<double>> rhom;
  edm::Handle<std::vector<double>> rhoCorr;
  edm::Handle<std::vector<double>> rhomCorr;
  edm::Handle<std::vector<double>> rhoCorr1Bin;
  edm::Handle<std::vector<double>> rhomCorr1Bin;
  
  // edm::Handle<std::vector<double>> rhoGrid;
  // edm::Handle<std::vector<double>> meanRhoGrid;
  // edm::Handle<std::vector<double>> etaMinRhoGrid;
  // edm::Handle<std::vector<double>> etaMaxRhoGrid;
  
  edm::Handle<std::vector<double>> ptJets;
  edm::Handle<std::vector<double>> areaJets;
  edm::Handle<std::vector<double>> etaJets;

  edm::Handle<std::vector<double>> rhoFlowFitParams;
  edm::Handle<std::vector<int>> nTow;
  edm::Handle<std::vector<double>> towExcludePt;
  edm::Handle<std::vector<double>> towExcludePhi;
  edm::Handle<std::vector<double>> towExcludeEta;
  
  iEvent.getByToken(etaToken_, etaRanges);
  iEvent.getByToken(rhoToken_, rho);
  iEvent.getByToken(rhomToken_, rhom);
  iEvent.getByToken(rhoCorrToken_, rhoCorr);
  iEvent.getByToken(rhomCorrToken_, rhomCorr);
  iEvent.getByToken(rhoCorr1BinToken_, rhoCorr1Bin);
  iEvent.getByToken(rhomCorr1BinToken_, rhomCorr1Bin);
  // iEvent.getByToken(rhoGridToken_, rhoGrid);
  // iEvent.getByToken(meanRhoGridToken_, meanRhoGrid);
  // iEvent.getByToken(etaMinRhoGridToken_, etaMinRhoGrid);
  // iEvent.getByToken(etaMaxRhoGridToken_, etaMaxRhoGrid);
  
  iEvent.getByToken(ptJetsToken_, ptJets);
  iEvent.getByToken(areaJetsToken_, areaJets);
  iEvent.getByToken(etaJetsToken_, etaJets);

  if (useModulatedRho_) {
    iEvent.getByToken(rhoFlowFitParamsToken_, rhoFlowFitParams);
    iEvent.getByToken(nTowToken_, nTow);
    iEvent.getByToken(towExcludePtToken_, towExcludePt);
    iEvent.getByToken(towExcludePhiToken_, towExcludePhi);
    iEvent.getByToken(towExcludeEtaToken_, towExcludeEta);
  }
  
  int neta = (int)etaRanges->size();
  for(int ieta = 0; ieta<(neta-1); ieta++) {
    rhoObj_.etaMin.push_back(etaRanges->at(ieta));
    rhoObj_.etaMax.push_back(etaRanges->at(ieta+1));
    rhoObj_.rho.push_back(rho->at(ieta));
    rhoObj_.rhom.push_back(rhom->at(ieta));
    rhoObj_.rhoCorr.push_back(rhoCorr->at(ieta));
    rhoObj_.rhomCorr.push_back(rhomCorr->at(ieta));
    rhoObj_.rhoCorr1Bin.push_back(rhoCorr1Bin->at(ieta));
    rhoObj_.rhomCorr1Bin.push_back(rhomCorr1Bin->at(ieta));
  }

  int njets = (int)ptJets->size();
  for(int ijet = 0; ijet<njets; ijet++) {
    rhoObj_.ptJets.push_back(ptJets->at(ijet));
    rhoObj_.areaJets.push_back(areaJets->at(ijet));
    rhoObj_.etaJets.push_back(etaJets->at(ijet));
  }

  if (useModulatedRho_) {
    rhoObj_.rhoFlowFitParams = *rhoFlowFitParams;
    rhoObj_.nTow = *nTow;
    rhoObj_.towExcludePt = *towExcludePt;
    rhoObj_.towExcludePhi = *towExcludePhi;
    rhoObj_.towExcludeEta = *towExcludeEta;
  }
  
  // int netaGrid = (int)rhoGrid->size();
  // for(int igrid = 0; igrid<netaGrid; igrid++) {
  //   rhoObj_.rhoGrid.push_back(rhoGrid->at(igrid));
  //   rhoObj_.meanRhoGrid.push_back(meanRhoGrid->at(igrid));
  //   rhoObj_.etaMinRhoGrid.push_back(etaMinRhoGrid->at(igrid));
  //   rhoObj_.etaMaxRhoGrid.push_back(etaMaxRhoGrid->at(igrid));
  // }
  
  tree_->Fill();
}