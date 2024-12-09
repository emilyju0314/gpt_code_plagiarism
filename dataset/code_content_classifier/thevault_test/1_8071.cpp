void CalHelixFinderAlg::findWorstResidHitInFitPhiZ (CalHelixFinderData& Helix,
						      PhiZFitInfo_t&      PhiZInfo,
						      HitInfo_t&          WorstFaceHit,
						      float&             Resid){
    PanelZ_t*      panelz(0);
    FaceZ_t*       facez(0);
    float         z, phi, weight(PhiZInfo.weight), xdphi, dphi, err;

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
	  phi      = z*Helix._szphi.dfdz() + Helix._szphi.phi0();
	  dphi     = fabs(hit->_hphi - phi);
	  err      = _sigmaPhi;

	  if (PhiZInfo.useInteligentWeight == 1){
	    weight = hit->_zphiWeight;//calculatePhiWeight(*hit,  helCenter, radius, 0, PhiZInfo.banner);
	    err    = 1./sqrt(weight);
	  }

	  xdphi = dphi/err;

	  if ( xdphi > Resid) {
	    WorstFaceHit.face          = f;
	    WorstFaceHit.panel         = p;
	    WorstFaceHit.panelHitIndex = index;

	    Resid                = xdphi;
	  }
	  
	}//end panel-hits loop
	
      }//end panels loop
    }//end faces loop
  
  }