void CalHelixFinderAlg::findGoodFaceHitInFitPhiZ (CalHelixFinderData& Helix,
						    PhiZFitInfo_t&      PhiZInfo,
						    HitInfo_t&          GoodFaceHit,
						    float&              FaceHitChi2){
      PanelZ_t*      panelz(0);
      int            firstPanel(0);
      float         dphi, err, xdphi, phi_ref;

      FaceZ_t*       facez     = &Helix._oTracker[PhiZInfo.faceId];
      float         z         = Helix._zFace[PhiZInfo.faceId];
      XYZVectorF         helCenter = Helix._center;
      float         radius    = Helix._radius;
      float         weight    = PhiZInfo.weight;

      if (Helix._sxy.qn() > 0) {
	helCenter = XYZVectorF( Helix._sxy.x0(), Helix._sxy.y0(), 0);
	radius    = Helix._sxy.radius();
      }
  
      if (PhiZInfo.faceId == PhiZInfo.seedIndex.face) firstPanel = PhiZInfo.seedIndex.panel;

      for (int p=firstPanel; p<FaceZ_t::kNPanels; ++p){
	panelz = &facez->panelZs[p];
	int       nhits  = panelz->nChHits();
	int       seedPanelIndex(0);
	if (nhits == 0)                                                                    continue;
	if ( (PhiZInfo.faceId == PhiZInfo.seedIndex.face )  && 
	     (p               == PhiZInfo.seedIndex.panel)  && 
	     (PhiZInfo.seedIndex.panelHitIndex >=0) ) seedPanelIndex = PhiZInfo.seedIndex.panelHitIndex - panelz->idChBegin;  

	for (int i=seedPanelIndex; i<nhits; ++i){
	  int             index = panelz->idChBegin + i;
	  mu2e::ComboHit* hit   = &Helix._chHitsToProcess[index];
	  PhiZInfo.dz           = z - PhiZInfo.zlast;
	  // predicted value of phi
	  phi_ref  = z*PhiZInfo.dfdz + PhiZInfo.phi0;	
	  // resolve 2PI ambiguity
	  resolve2PiAmbiguity(hit, helCenter, phi_ref, dphi);

	  dphi     = fabs(dphi);
	  err      = _sigmaPhi;

	  if (PhiZInfo.useInteligentWeight == 1){
	    weight  = calculatePhiWeight(*hit, helCenter, radius, 0, PhiZInfo.banner);
	    err     = 1./sqrt(weight);
	  }
	  hit->_zphiWeight = weight;

	  xdphi = dphi/err;

	  if (_debug > 10) {
	    printf("[CalHelixFinderAlg::doLinearFitPhiZ:LOOP] %08x %2i %6i %3i %12.5f %12.5f %10.5f %10.3f %10.3f %10.3f %10.5f %10.5f %5.3f\n",
		   *((int*) &hit->_flag), Helix._hitsUsed[index],
		   hit->strawId().straw(), i,
		   z, hit->_hphi, dphi, xdphi, PhiZInfo.zlast, PhiZInfo.dz,
		   PhiZInfo.dfdz, Helix._szphi.dfdz(), Helix._szphi.chi2DofLine());
	  }

	  if (Helix._hitsUsed[index] != 1)                     continue;

	  if ( (PhiZInfo.doCleanUp == 1) && (xdphi > _maxXDPhi) ) {
	    Helix._hitsUsed[index] = 0;
	    ++PhiZInfo.nPointsRemoved;
	    continue;
	  }

	  if (xdphi < FaceHitChi2){
	    FaceHitChi2               = xdphi;
	    GoodFaceHit.face          = PhiZInfo.faceId;
	    GoodFaceHit.panel         = p;
	    GoodFaceHit.panelHitIndex = index;
	  }
	}
	
      }//end panels loop

  
  }