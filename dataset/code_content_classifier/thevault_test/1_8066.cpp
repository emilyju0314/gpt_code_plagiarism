bool CalHelixFinderAlg::fitHelix(CalHelixFinderData& Helix) {
    bool retval(false);
					// initialize internal array of hits, print if requested
    //    fillXYZP(Helix); //2019-01-18: gianipez moved this into the CalHelixFinder_module to exploit the helicity loop-search
//-----------------------------------------------------------------------------
// 2014-11-09 gianipez: reset the track candidate parameters if a new time peak is used!
// so the previous candidate should not be compared to the new one at this level
//-----------------------------------------------------------------------------
    resetTrackParamters();
//-----------------------------------------------------------------------------
// save results in the very beginning
//-----------------------------------------------------------------------------
    if (_diag > 0) saveResults(Helix, 0);

    // if (_filter) {
    //   filterDist(Helix);
    //   if (_diag > 0) saveResults(_xyzp,Helix,1);
    // }

    doPatternRecognition(Helix);
//---------------------------------------------------------------------------
// 2014-11-11 gianipez changed the following if() statement to test the
// possibility of spead up the pattern recognition in presence of background
// how the number of good points may be different from the number used in sums ?
//---------------------------------------------------------------------------
    if (_debug != 0) {
      printf("[CalHelixFinderAlg::findHelix] Helix._nXYSh = %i goodPointsTrkCandidate = %i\n",
	     Helix._nXYSh, Helix._nStrawHits);//_goodPointsTrkCandidate);
    }

    if (Helix._nStrawHits < _minNHits ) {
      Helix._fit = TrkErrCode(TrkErrCode::fail,1); // small number of hits
    }
    else if ((Helix._radius < _rmin) || (Helix._radius > _rmax)) {
      Helix._fit = TrkErrCode(TrkErrCode::fail,2); // initialization failure
    }
    else if ((Helix._nXYSh < _minNHits) || (Helix._sxy.chi2DofCircle() > _chi2xyMax)) {
      Helix._fit = TrkErrCode(TrkErrCode::fail,3); // xy reconstruction failure
    }
    else if ((Helix._nZPhiSh < _minNHits) || (Helix._szphi.chi2DofLine() > _chi2zphiMax) ||
	     (fabs(Helix._szphi.dfdz()) < _minDfDz) || (fabs(Helix._szphi.dfdz()) > _maxDfDz)) {
      Helix._fit = TrkErrCode(TrkErrCode::fail,4); // phi-z reconstruction failure
    }
    else {
      //-----------------------------------------------------------------------------
      // success, form output
      //-----------------------------------------------------------------------------
      Helix._goodhits.clear();

      PanelZ_t*      panelz(0);
      FaceZ_t*       facez(0);

      for (int f=0; f<StrawId::_ntotalfaces; ++f){
	facez     = &Helix._oTracker[f];
	for (int p=0; p<FaceZ_t::kNPanels; ++p){
	  panelz = &facez->panelZs[p];
	  int  nhits = panelz->nChHits();
	  for (int i=0; i<nhits; ++i){   
	    int index = panelz->idChBegin + i;// facez->evalUniqueHitIndex(f,p,i);
	    if (Helix._hitsUsed[index] != 1)                continue;
	    Helix._goodhits.push_back(index); // HitInfo_t(f,p,index));
	  }
	}
      }

      defineHelixParams(Helix);
      retval = true;
    }

    return retval;
  }