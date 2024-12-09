void DeltaFinder2::pruneSeeds(int Station) {
    int nseeds =  _data.seedHolder[Station].size();

    for (int i1=0; i1<nseeds-1; i1++) {
      DeltaSeed* ds1 = _data.seedHolder[Station][i1];
      if (ds1->fGood < 0) continue;

      if (ds1->Chi2Tot() > _maxChi2Tot) {
	ds1->fGood = -1000-i1;
	continue;
      }

      float tmean1 = (ds1->fMinTime+ds1->fMaxTime)/2.;

      for (int i2=i1+1; i2<nseeds; i2++) {
	DeltaSeed* ds2 = _data.seedHolder[Station][i2];
	if (ds2->fGood < 0) continue;

	if (ds2->Chi2Tot() > _maxChi2Tot) {
	  ds2->fGood = -1000-i2;
	  continue;
	}

	float tmean2 = (ds2->fMinTime+ds2->fMaxTime)/2.;

	if (fabs(tmean1-tmean2) > _maxDriftTime) continue;
//-----------------------------------------------------------------------------
// the two segments are close in time and space, check hit overlap
// *FIXME* didn't check distance !!!!!
// so far, allow duplicates during the search
// the two DeltaSeeds share could have significantly overlapping hit content
//-----------------------------------------------------------------------------
	int noverlap = 0;
	int nfaces_with_overlap = 0;
	for (int face=0; face<kNFaces; face++) {
	  int nov = 0;
	  int nh1 = ds1->hitlist[face].size();
	  for (int ih1=0; ih1<nh1; ih1++) {
	    const HitData_t* hh1 = ds1->hitlist[face][ih1];
	    int nh2 = ds2->hitlist[face].size();
	    for (int ih2=0; ih2<nh2; ih2++) {
	      const HitData_t* hh2 = ds2->hitlist[face][ih2];
	      if (hh2 == hh1) {
		nov += 1;
		break;
	      }
	    }
	  }
	  noverlap += nov;
	  if (nov != 0) nfaces_with_overlap += 1;
	}
//-----------------------------------------------------------------------------
// special treatment of 2-hit seeds to reduce the number of ghosts
//-----------------------------------------------------------------------------
	if (ds1->fNHitsTot == 2) {
	  if (nfaces_with_overlap > 0) {
	    if (ds2->fNFacesWithHits > 2) {
	      ds1->fGood = -1000-i2;
	      break;
	    }
	    else {
					// the second one also has 2 faces with hits

	      if (ds1->Chi2AllDof() <  ds2->Chi2AllDof()) ds2->fGood = -1000-i1;
	      else {
		ds1->fGood = -1000-i2;
		break;
	      }
	    }
	  }
	}

	if (ds2->fNHitsTot == 2) {
	  if (nfaces_with_overlap > 0) {
//-----------------------------------------------------------------------------
// the 2nd seed has only 2 hits and there is an overlap
//-----------------------------------------------------------------------------
	    if (ds1->fNFacesWithHits > 2)                 ds2->fGood = -1000-i1;
	    else {
					// the second one also has 2 faces with hits

	      if (ds1->Chi2AllDof() <  ds2->Chi2AllDof()) ds2->fGood = -1000-i1;
	      else {
		ds1->fGood = -1000-i2;
		break;
	      }
	    }
	  }
	}

	if (nfaces_with_overlap > 1) {
	  if ((noverlap >= ds1->fNHitsTot*0.6) || (noverlap >= 0.6*ds2->fNHitsTot)) {
//-----------------------------------------------------------------------------
// overlap significant, leave in only one DeltaSeed - which one? 
//-----------------------------------------------------------------------------
	    if      (ds1->Chi2AllDof() <  ds2->Chi2AllDof()) ds2->fGood = -1000-i1;
	    else if (ds1->Chi2AllDof() >= ds2->Chi2AllDof()) {
	      ds1->fGood = -1000-i2;
	      break;
	    }
	    else {
//-----------------------------------------------------------------------------
// the same number of hits, choose candidate with lower chi2
// should not be getting here
//-----------------------------------------------------------------------------
	      if (ds1->Chi2AllDof() < ds2->Chi2AllDof()) ds2->fGood = -1000-i1;
	      else {
		ds1->fGood = -1000-i2;
		break;
	      }
	    }
	  }
	}
      }
    }
  }