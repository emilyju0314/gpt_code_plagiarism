void DeltaFinder::getNeighborHits(DeltaSeed* Seed, int Face, int Face2, PanelZ_t* panelz) {

    DeltaFinderTypes::Intersection_t     res;

    vector<HitData_t*> hits;

    const HitData_t* hd1 = Seed->HitData(Face,0);
    // const Straw* straw1  = hd1->fStraw;
    float minrad         = hd1->fHit->centerPosCLHEP().perp();//straw1->getMidPoint().perp();
    float maxrad         = minrad;

    // for (int l=0; l<2; ++l) {
    int nh = panelz->fHitData.size();
    for (int h=0; h<nh; ++h) {
      HitData_t* hd  = &panelz->fHitData[h];
      if (hd == hd1) continue ;
      const ComboHit* sh = hd->fHit;

      if (sh->time()-Seed->T0Max() > _maxDriftTime          ) continue;
      if (sh->time()               < Seed->T0Min()          ) continue;

      hd->fDr        = fabs(hd->fRMid-minrad);
      hits.push_back(hd);
    }
    // }
    //-----------------------------------------------------------------------------
    // sorted hits in dr wrt the seed hit.
    // I know that sorting could be done with more elegance, don't care at the moment
    // also the diagnostics data could be fully separated from the data itself
    //-----------------------------------------------------------------------------
    int nhits = hits.size();
    for (int i=0; i<nhits-1; i++) {
      HitData_t** hi = &hits[i];
      for (int j=i+1; j<nhits; j++) {
        HitData_t** hj = &hits[j];
        if ((*hi)->fDr >= (*hj)->fDr) {
          HitData_t* h = hits[i];
          hits[i]      = hits[j];
          hits[j]      = h;
        }
      }
    }
//-----------------------------------------------------------------------------
// hits are orders in distance from the first pre-seed hit
// loop over them again, 'hd2' - the second seed hit
//-----------------------------------------------------------------------------
    const HitData_t* hd2 = Seed->HitData(Face2,0);

    for (int i=0; i<nhits; i++) {
      const HitData_t* hd = hits[i];
      float rad     = hd->fRMid;
      if ((minrad-rad > 10) || (rad-maxrad > 10) ) continue;
//-----------------------------------------------------------------------------
// radially we're OK, check distance from the intersection
//-----------------------------------------------------------------------------
      CLHEP::Hep3Vector pos;

      DeltaFinderTypes::findIntersection(hd, hd2, &res);

      float chi = res.wd1/hd->fSigW;

      if (chi*chi < _maxChi2Neighbor) {
//-----------------------------------------------------------------------------
// OK along the wire, add hit as a neighbor
//-----------------------------------------------------------------------------
	if (rad < minrad) minrad = rad;
	else              maxrad = rad;

	Seed->hitlist[Face].push_back(hd);

	const ComboHit* sh = hd->fHit;
	if (sh->time() < Seed->fMinTime) Seed->fMinTime = sh->time();
	if (sh->time() > Seed->fMaxTime) Seed->fMaxTime = sh->time();
      }
    }
  }