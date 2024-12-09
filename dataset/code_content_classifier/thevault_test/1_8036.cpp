int DeltaFinder::checkDuplicates(int Station, int Face1, const HitData_t* Hit1, int Face2, const HitData_t* Hit2) {

    bool h1_found(false), h2_found(false);

    int nseeds = _data.seedHolder[Station].size();
    for (int i=0; i<nseeds; i++) {
      DeltaSeed* seed = _data.seedHolder[Station][i];

      int nhits = seed->hitlist[Face1].size();
      for (int ih=0; ih<nhits; ih++) {
        const HitData_t* hit = seed->hitlist[Face1][ih];
        if (hit == Hit1) {
          h1_found = true;
          break;
        }
      }

      if (! h1_found) continue;  // with the next seed
//-----------------------------------------------------------------------------
// Hit1 was found, search the same seed for Hit2
//-----------------------------------------------------------------------------
      nhits = seed->hitlist[Face2].size();
      for (int ih=0; ih<nhits; ih++) {
        const HitData_t* hit = seed->hitlist[Face2][ih];
        if (hit == Hit2) {
          h2_found = true;
          break;
        }
      }

      if (h2_found) {
//-----------------------------------------------------------------------------
// both Hit1 and Hit2 were found within the same seed
//-----------------------------------------------------------------------------
	return 1;
      }
    }
    return 0;
  }