int CalHelixFinderAlg::refineHelixParameters(CalHelixFinderData& Trk,
					       HitInfo_t           SeedIndex,
					       const char*         Banner,
					       int                 Print  ) {
    auto           hitsUsed = Trk._hitsUsed;
    float         x, y, r, r_start;
    float         hitChi2Worst;

    int            pointsRemoved(0);

    HitInfo_t     iworst;//(-1, -1);
    float         wtWorst;
    float         chi2, chi2_min;

    XYZVectorF          hitPos, strawDir, helCenter, helCenter_start;
    mu2e::ComboHit* hit(0);
    //    FaceZ_t*        facez(0);
    //    PanelZ_t*       panelz(0);
    
    int            hitUsedIndex(-1);

    int            rc(0);               // success-oriented initialization :)
					// initialize helix 
    r  = Trk._sxy.radius();
    helCenter.SetX( Trk._sxy.x0());
    helCenter.SetY( Trk._sxy.y0());

    helCenter_start = helCenter;
    r_start         = r;

    if (_debug > 5) {
      printf("[CalHelixFinderAlg::refineHelixParameters] BEGIN               x0 = %8.3f y0 = %8.3f radius = %8.3f chi2 = %8.3f \n",
	     Trk._sxy.x0(), Trk._sxy.y0(), Trk._sxy.radius(), Trk._sxy.chi2DofCircle());
      printf("[CalHelixFinderAlg::refineHelixParameters] i       X        Y        dx        dy         costh        sinth2         e2     radial-dist\n");
    }

    doWeightedCircleFit (Trk,SeedIndex,helCenter,r,Print,Banner);
//-----------------------------------------------------------------------------
// recalcute weights using most recent helix parameters
//-----------------------------------------------------------------------------
    doWeightedCircleFit (Trk,SeedIndex,helCenter,r,Print,Banner);

    //now initialize the LsqSum4 variable
    // sxyw.init(Trk._sxy);

    searchWorstHitWeightedCircleFit(Trk,SeedIndex,helCenter,r,iworst,hitChi2Worst);

    chi2     = Trk._sxy.chi2DofCircle();
    chi2_min = chi2;

    if (_debug > 5) {
      printf("[CalHelixFinderAlg::refineHelixParameters] npt = %3.0f x0 = %8.3f y0 = %8.3f radius = %8.3f chi2 = %8.3f iworst=%3i chi2Worst = %8.3f\n",
	     Trk._sxy.qn(),Trk._sxy.x0(),Trk._sxy.y0(),Trk._sxy.radius(),Trk._sxy.chi2DofCircle(),iworst.panel,hitChi2Worst);
    }

    if ((chi2 <= _chi2xyMax) && (hitChi2Worst <= _hitChi2Max)) goto F_END;
//-----------------------------------------------------------------------------
// one of the chi2's is above the threshold, cleanup is needed
//-----------------------------------------------------------------------------
    if (_debug > 5) printf("[CalHelixFinderAlg::refineHelixParameters] : START CLEANUP\n");  
  NEXT_ITERATION:;

    cleanUpWeightedCircleFit(Trk,SeedIndex,iworst);

    if (iworst.panel >= 0) {
      // facez   = &Trk._oTracker[iworst.face];
      // panelz  = &facez->panelZs[iworst.panel];
      hitUsedIndex = iworst.panelHitIndex;
      hit     = &Trk._chHitsToProcess[hitUsedIndex];
      x       = hit->_pos.x();
      y       = hit->_pos.y();
      wtWorst = hit->_xyWeight;
      
					// remove point from the track, this is why need to return weights
      Trk._sxy.removePoint(x, y, wtWorst);
      Trk._nXYSh -=hit->nStrawHits();

      //      hitUsedIndex = facez->evalUniqueHitIndex(iworst);
      Trk._hitsUsed[hitUsedIndex] = 0;

      Trk._nComboHits -= 1;
      Trk._nStrawHits -= hit->nStrawHits();
      ++pointsRemoved;

      if (_debug > 5) {
	printf("[CalHelixFinderAlg::refineHelixParameters]  x0 = %8.3f y0 = %8.3f radius = %8.3f  chi2 = %5.5f chi2Maxxy = %5.5f index point removed = %i\n",
	       Trk._sxy.x0(), Trk._sxy.y0(), Trk._sxy.radius(), Trk._sxy.chi2DofCircle(), _chi2xyMax, iworst.panel);//FIXME!
      }
					// update helix parameters and refit
      r  = Trk._sxy.radius();
      helCenter.SetX(Trk._sxy.x0());
      helCenter.SetY(Trk._sxy.y0());

      doWeightedCircleFit (Trk,SeedIndex,helCenter,r,0,Banner);

					// update the chi2 value
      chi2_min = Trk._sxy.chi2DofCircle();
    }
//-----------------------------------------------------------------------------
// recalculate the worst radial residual
//-----------------------------------------------------------------------------
  CHECK_RESIDUALS: ;
    searchWorstHitWeightedCircleFit(Trk,SeedIndex,helCenter,r,iworst,hitChi2Worst);
//-----------------------------------------------------------------------------
// if a hit contributes chi2 > _hitCHi2Max, remove it and go back looking for the next such hit
//-----------------------------------------------------------------------------
    if (iworst.panel >= 0) {
      // facez   = &Trk._oTracker[iworst.face];
      // panelz  = &facez->panelZs[iworst.panel];//panelz  = &Trk._oTracker[iworst.Panel];
      hitUsedIndex = iworst.panelHitIndex;
      hit     = &Trk._chHitsToProcess[hitUsedIndex];
      x       = hit->_pos.x();
      y       = hit->_pos.y();
      wtWorst = hit->_xyWeight;
					// remove point from the track and mark it
      Trk._sxy.removePoint(x, y, wtWorst);
      Trk._nXYSh -=hit->nStrawHits();

      //      hitUsedIndex = facez->evalUniqueHitIndex(iworst);
      Trk._hitsUsed[hitUsedIndex] = 0;

      Trk._nComboHits -= 1;
      Trk._nStrawHits -= hit->nStrawHits();
      ++pointsRemoved;

      if (_debug > 5) {
	printf("[CalHelixFinderAlg::refineHelixParameters:REMOVE] iworst=%3i (x0,y0,R) = (%8.3f, %8.3f, %8.3f) chi2 = %8.3f chi2Maxxy = %8.3f\n",
	       iworst.panel, Trk._sxy.x0(), Trk._sxy.y0(), Trk._sxy.radius(), Trk._sxy.chi2DofCircle(), _chi2xyMax);//FIXME!
      }
					// update helix info
      r  = Trk._sxy.radius();
      helCenter.SetX(Trk._sxy.x0());
      helCenter.SetY(Trk._sxy.y0());
					// refit helix and update the chi2 value

      doWeightedCircleFit (Trk,SeedIndex,helCenter,r,0,Banner);
      chi2_min = Trk._sxy.chi2DofCircle();
                                                            goto CHECK_RESIDUALS;
    }

    if ((chi2_min >= _chi2xyMax) && (iworst.panel >= 0)) {
//-----------------------------------------------------------------------------
// still bad chi2, repeat the cleanup cycle
//-----------------------------------------------------------------------------
      if (Trk._nStrawHits > _minNHits)                         goto NEXT_ITERATION;
      else  {
//-----------------------------------------------------------------------------
// number of points too small, bail out
//-----------------------------------------------------------------------------
	rc = -1;
      }
    }
    else if (chi2_min < _chi2xyMax) {
//-----------------------------------------------------------------------------
// 2018-01-03 PM: not sure what exactly this is supposed to mean, but...
//-----------------------------------------------------------------------------
      rc = 1;
    }

  F_END:;
    if (_debug > 5) {
      printf("[CalHelixFinderAlg::refineHelixParameters] END: RC=%1i", rc);
      printf(" npt:%3.0f x0: %8.3f y0: %8.3f R: %8.3f chi2: %9.3f N(removed):%3i\n",
	     Trk._sxy.qn(), Trk._sxy.x0(), Trk._sxy.y0(), Trk._sxy.radius(), Trk._sxy.chi2DofCircle(), pointsRemoved);
    }

    if (rc >= 0) {
//-----------------------------------------------------------------------------
// update circle parameters
//-----------------------------------------------------------------------------
      // Trk._sxyw.init(sxyw);
      Trk._center.SetX(Trk._sxy.x0());
      Trk._center.SetY(Trk._sxy.y0());
      Trk._radius = Trk._sxy.radius();
      //      Trk._chi2   = Trk._sxy.chi2DofCircle();

    }else {
      Trk._hitsUsed = hitsUsed;   //restore the info of the used-hits that was originally passed to the procedure      
      doWeightedCircleFit (Trk,SeedIndex,helCenter_start,r_start,0,Banner);
    }

    return rc;
  }