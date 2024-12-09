void    CalHelixFinderAlg::cleanUpWeightedCircleFit(CalHelixFinderData& Helix,
						      HitInfo_t          SeedIndex,
						      HitInfo_t&         IWorst)
  {
    LsqSums4   sxy;
    float     chi2, chi2_min (-1.), x, y;

    //reset the coordinates of the worst hit found previousl
    IWorst.face          = -1;
    IWorst.panel         = -1;
    IWorst.panelHitIndex = -1;

    mu2e::ComboHit* hit(0);
    PanelZ_t*       panelz(0);
    FaceZ_t*        facez(0);
 
    for (int f=SeedIndex.face; f<StrawId::_ntotalfaces; ++f){
      facez     = &Helix._oTracker[f];
      int  firstPanel(0);
      if (f == SeedIndex.face) firstPanel = SeedIndex.panel;

      for (int p=firstPanel; p<FaceZ_t::kNPanels; ++p){
	panelz = &facez->panelZs[p];//&Helix._oTracker[p];
	int  nhitsPerPanel  = panelz->nChHits();
	int  seedPanelIndex(0);
	if (nhitsPerPanel == 0)                                                             continue;
	if ( (f==SeedIndex.face) && (p==SeedIndex.panel) && (SeedIndex.panelHitIndex >=0)) seedPanelIndex = SeedIndex.panelHitIndex - panelz->idChBegin;  

	for (int i=seedPanelIndex; i<nhitsPerPanel; ++i){   
	  int     index = panelz->idChBegin + i;
	  hit = &Helix._chHitsToProcess[index];
	  //	  int index = facez->evalUniqueHitIndex(f,p,i);
	  if (Helix._hitsUsed[index] != 1)                    continue;

	  sxy.init(Helix._sxy);

	  x  = hit->_pos.x();
	  y  = hit->_pos.y();

	  sxy.removePoint(x, y, hit->_xyWeight);

	  chi2  = sxy.chi2DofCircle();

	  if ((chi2 < chi2_min) || ( (i == SeedIndex.panelHitIndex) && (p == SeedIndex.panel) && (f == SeedIndex.face)) ) {
	    chi2_min             = chi2;
	    IWorst.face          = f;
	    IWorst.panel         = p;
	    IWorst.panelHitIndex = index;	    
	  }
	}
      }//end panels loop
    }//end faces loop
  }