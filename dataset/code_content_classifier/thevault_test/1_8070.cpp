void CalHelixFinderAlg::findWorstChi2HitInFitPhiZ (CalHelixFinderData& Helix,
						     PhiZFitInfo_t&      PhiZInfo,
						     HitInfo_t&          WorstFaceHit,
						     float&             HitChi2){
    PanelZ_t*      panelz(0);
    FaceZ_t*       facez(0);
    float         z, phi, weight(PhiZInfo.weight), chi2;
    ::LsqSums4     szphi;
 
    for (int f=PhiZInfo.seedIndex.face; f<StrawId::_ntotalfaces; ++f){
      facez     = &Helix._oTracker[f];
      z         = Helix._zFace[f];
      int            firstPanel(0);
      if (f == PhiZInfo.seedIndex.face) firstPanel = PhiZInfo.seedIndex.panel;
      for (int p=firstPanel; p<FaceZ_t::kNPanels; ++p){
	panelz = &facez->panelZs[p];
	int       nhits  = panelz->nChHits();
	int       seedPanelIndex(0);
	if (nhits == 0)                                         continue;
	if ( (f      == PhiZInfo.seedIndex.face )  && 
	     (p      == PhiZInfo.seedIndex.panel)  && 
	     (PhiZInfo.seedIndex.panelHitIndex >=0) ) seedPanelIndex = PhiZInfo.seedIndex.panelHitIndex - panelz->idChBegin;  

	for (int i=seedPanelIndex; i<nhits; ++i){
	  int             index = panelz->idChBegin + i;
	  mu2e::ComboHit* hit   = &Helix._chHitsToProcess[index];
	  if (Helix._hitsUsed[index] != 1)            continue; 
	  
	  szphi.init(Helix._szphi);
	  phi      = hit->_hphi;

	  if (PhiZInfo.useInteligentWeight == 1){
	    weight = hit->_zphiWeight;
	  }

	  szphi.removePoint(z, phi, weight);
	  chi2 = szphi.chi2DofLine();
	  if (chi2 < HitChi2) {
	    WorstFaceHit.face          = f;
	    WorstFaceHit.panel         = p;
	    WorstFaceHit.panelHitIndex = index;
	    HitChi2                    = chi2;
	  }
	  
	}//end panel-hits loop
	
      }//end panels loop
    }//end faces loop
  
  }