void    CalHelixFinderAlg::searchWorstHitWeightedCircleFit(CalHelixFinderData& Helix,
							     HitInfo_t           SeedIndex,
							     const XYZVectorF&       HelCenter,
							     float&             Radius,
							     HitInfo_t&          Iworst,
							     float&             HitChi2Worst)
  {
    HitChi2Worst         = _hitChi2Max;
    Iworst.face          = -1;
    Iworst.panel         = -1;
    Iworst.panelHitIndex = -1;

    float     dr, hitChi2;
  
    mu2e::ComboHit* hit(0);
    FaceZ_t*        facez(0);
    PanelZ_t*       panelz(0);
    //    FaceZ_t*       seedFacez = &Helix._oTracker[Helix._seedIndex.face];


    for (int f=SeedIndex.face; f<StrawId::_ntotalfaces;  ++f){
      facez     = &Helix._oTracker[f]; 
      int  firstPanel(0);
      if (f == SeedIndex.face) firstPanel = SeedIndex.panel;
      for (int p=firstPanel; p<FaceZ_t::kNPanels; ++p){
	panelz = &facez->panelZs[p];//Helix._oTracker[p];
	int  nhitsPerPanel  = panelz->nChHits();
	int  seedPanelIndex(0);
	if (nhitsPerPanel == 0)                                                            continue;
	if ((f==SeedIndex.face) && (p==SeedIndex.panel) && (SeedIndex.panelHitIndex >=0)) seedPanelIndex = SeedIndex.panelHitIndex - panelz->idChBegin;  

	for (int i=seedPanelIndex; i<nhitsPerPanel; ++i){   
	  int     index = panelz->idChBegin + i;
	  hit = &Helix._chHitsToProcess[index];
	  if (Helix._hitsUsed[index] != 1)                    continue;

	  dr      = calculateRadialDist(hit->_pos,HelCenter,Radius);
	  hitChi2 = dr*dr*hit->_xyWeight;

	  // store info out the radial residual
	  // if ((SeedIndex.face == 0) && (SeedIndex.panel == 0) && (SeedIndex.panelHitIndex == 0)) {
	  // hit->_drFromPred  = fabs(dr);//hitChi2;
	  // float dzFromSeed = facez->z - seedFacez->z;              // expected to be positive (non-negative)
	  //	    hit->_dzFromSeed  = dzFromSeed;//FIXME!
	  // }

	  if (hitChi2 > HitChi2Worst) {
	    HitChi2Worst         = hitChi2;
	    Iworst.face          = f;
	    Iworst.panel         = p;
	    Iworst.panelHitIndex = index;
	  }
	}
      }//end panels loop
    }//end faces loop
  }