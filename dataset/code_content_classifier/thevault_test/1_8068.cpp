void   CalHelixFinderAlg::countUsedHits           (CalHelixFinderData& Helix,
						     HitInfo_t           SeedIndex,
						     int&                NComboHits, 
						     int&                NPoints){
    FaceZ_t*        facez(0);
    PanelZ_t*       panelz(0);
    mu2e::ComboHit* hit(0);
    int             index(0);

    for (int f=SeedIndex.face; f<StrawId::_ntotalfaces;  ++f){
      facez     = &Helix._oTracker[f]; 
      int  firstPanel(0);
      if (f == SeedIndex.face) firstPanel = SeedIndex.panel;
      for (int p=firstPanel; p<FaceZ_t::kNPanels; ++p){
	panelz = &facez->panelZs[p];
	int  nhitsPerPanel  = panelz->nChHits();
	int  seedPanelIndex(0);
	if (nhitsPerPanel == 0)                                 continue;
	if ( (f==SeedIndex.face) && (p==SeedIndex.panel) && (SeedIndex.panelHitIndex >=0)) seedPanelIndex = SeedIndex.panelHitIndex - panelz->idChBegin;  

	for (int i=seedPanelIndex; i<nhitsPerPanel; ++i){   
	  index = panelz->idChBegin + i;
	  hit   = &Helix._chHitsToProcess[index];
	  if (Helix._hitsUsed[index] > 0 )  {
	    ++NComboHits;
	    NPoints += hit->nStrawHits();
	  }
	}
      }//endl panels loop
    }//end face loop
  }