void CalHelixFinderAlg::fillFaceOrderedHits(CalHelixFinderData& Helix) {

//-----------------------------------------------------------------------------
// set the CaloCluster of CalHelixFinderAlg: this info is stored in the TimeCluster
//-----------------------------------------------------------------------------     
    setCaloCluster(Helix);

    static const float pi(M_PI);
    static const float twopi(2*pi);

    float clPhi(-9999.);

    if (fCaloTime > 0) clPhi = polyAtan2(fCaloY,fCaloX);

    const vector<StrawHitIndex>& shIndices = Helix._timeCluster->hits();
    ChannelID cx, co;

    int     size           = Helix._timeCluster->nhits();
    int     nFiltPoints(0), nFiltStrawHits(0);
    //--------------------------------------------------------------------------------
    // if (Helix.shpos() != 0) {
    int loc;
    StrawHitFlag flag;

    //sort the hits by z coordinate
    ComboHitCollection ordChCol;
    ordChCol.reserve(size);

    if (_debug >0 ){
      printf("-----------------------------------------------------------------------------------/n");
      printf("[CalHelixFinderAlg::fillFaceOrderedHits]  Plane   Panel  Layer Straw     x          y           z  \n");
    }

    for (int i=0; i<size; ++i) {
      loc = shIndices[i];
      flag         = Helix.shfcol()->at(loc);
      //-----------------------------------------------------------------------------
      // select hits: don't reuse straw hits
      //-----------------------------------------------------------------------------
      int good_hit = flag.hasAllProperties(_hsel  );
      int bkg_hit  = flag.hasAnyProperty  (_bkgsel);
      // int used_hit = flag.hasAnyProperty  (StrawHitFlag::calosel);
      // if (good_hit && (! bkg_hit) && (! used_hit)) {
      if (good_hit && (! bkg_hit) ) {
	const ComboHit& ch  = Helix.chcol()->at(loc);

	if (ch.energyDep() > _maxHitEnergy)                 continue;

	//skip the hit if it doesn't rely on the semi-plane where the calo-lcuster is
	if (_filter) {
	  float chPhi = polyAtan2(ch.pos().y(), ch.pos().x());
	  float dphi  = chPhi - clPhi;

	  if (dphi >  pi) dphi -= twopi;
	  if (dphi < -pi) dphi += twopi;
	    
	  if (fabs(dphi) > pi/2)                            continue;
	}

	if (_debug >0 ){
	  const mu2e::Straw* straw;
	  
	  straw = &_tracker->getStraw(ch.strawId());//ndex());

	  printf("[CalHelixFinderAlg::fillFaceOrderedHits]  %5i  %5i   %5i   %5i   %8.3f   %8.3f    %10.3f\n",
		 straw->id().getPlane(),
		 straw->id().getPanel(),
		 straw->id().getLayer(),
		 straw->id().getStraw(),
		 ch.pos().x(), ch.pos().y(), ch.pos().z());
	}

	ordChCol.push_back(ComboHit(ch));
      }
    }
    std::sort(ordChCol.begin(), ordChCol.end(),panelcomp());

    for (unsigned i=0; i<ordChCol.size(); ++i) {
      ComboHit& ch = ordChCol[i];

      cx.Station                 = ch.strawId().station();//straw.id().getStation();
      cx.Plane                   = ch.strawId().plane() % 2;//straw.id().getPlane() % 2;
      cx.Face                    = ch.strawId().face();
      cx.Panel                   = ch.strawId().panel();//straw.id().getPanel();

      // get Z-ordered location
      Helix.orderID(&cx, &co);
     
      int os       = co.Station; 
      int of       = co.Face;
      //FIXME!!! COMPARE OF WITH ch.sid().uniqueFace()
      int op       = co.Panel;

      int       stationId = os;
      int       faceId    = of + stationId*StrawId::_nfaces*FaceZ_t::kNPlanesPerStation;//FaceZ_t::kNFaces;
      //	int       panelId   = op + faceId*FaceZ_t::kNPanels;//PerFace;
      FaceZ_t*  fz        = &Helix._oTracker[faceId];
      PanelZ_t* pz        = &fz->panelZs[op];
	
      if ((of < 0) || (of >  StrawId::_nfaces*FaceZ_t::kNPlanesPerStation  )) printf(" >>> ERROR: wrong face    number: %i\n",of);
      if ((op < 0) || (op >= FaceZ_t::kNPanels )) printf(" >>> ERROR: wrong panel   number: %i\n",op);

      Helix._chHitsToProcess.push_back(mu2e::ComboHit(ch));

      if (pz->idChBegin < 0 ){
	pz->idChBegin = Helix._chHitsToProcess.size() - 1;
	pz->idChEnd   = Helix._chHitsToProcess.size();	
      } else {
	pz->idChEnd   = Helix._chHitsToProcess.size();	
      }
	
      if (fz->idChBegin < 0 ){
	fz->idChBegin = Helix._chHitsToProcess.size() - 1;
	fz->idChEnd   = Helix._chHitsToProcess.size();	
      } else {
	fz->idChEnd   = Helix._chHitsToProcess.size();	
      }

      ++nFiltPoints;
      nFiltStrawHits += ch.nStrawHits();
    }
    
    Helix._nFiltPoints    = nFiltPoints;     
    Helix._nFiltStrawHits = nFiltStrawHits;  

    if (_debug > 0) printXYZP(Helix);
  }