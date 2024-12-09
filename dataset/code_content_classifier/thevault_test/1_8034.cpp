int DeltaFinder::recoverMissingHits() {

    int ndelta = _data.deltaCandidateHolder.size();
    for (int idelta=0; idelta<ndelta; idelta++) {
      DeltaCandidate* dc = &_data.deltaCandidateHolder[idelta];
//-----------------------------------------------------------------------------
// don't extend candidates made out of one segment - but there is no such
// start from the first station to define limits
//-----------------------------------------------------------------------------
      int s1 = dc->fFirstStation;
      int s2 = dc->fLastStation-1;
      int last(-1);
      float t0min(-1.), t0max(-1.);
//-----------------------------------------------------------------------------
// first check inside "holes", skip unused stations
//-----------------------------------------------------------------------------
      for (int i=s1; i<=s2; i++) {
	if (dc->seed[i] != nullptr) {
	  last  = i; 
	  t0min = dc->fT0Min[i];
	  t0max = dc->fT0Max[i];
	  continue;
	}
	if (_data.stationUsed[i] == 0) continue;
//-----------------------------------------------------------------------------
// define expected T0 limits
//-----------------------------------------------------------------------------
	dc->fT0Min[i] = t0min-_maxDtDs*(i-last);
	dc->fT0Max[i] = t0max+_maxDtDs*(i-last);
	recoverStation(dc,i);
      }

      last  = dc->fFirstStation;
      for (int i=last-1; i>=0; i--) {
//-----------------------------------------------------------------------------
// skip empty stations
//-----------------------------------------------------------------------------
	if (_data.stationUsed[i] == 0) continue;
	dc->fT0Min[i] = dc->fT0Min[dc->fFirstStation]-_maxDtDs*(dc->fFirstStation-i);
	dc->fT0Max[i] = dc->fT0Max[dc->fFirstStation]+_maxDtDs*(dc->fFirstStation-i);
	recoverStation(dc,i);
//-----------------------------------------------------------------------------
// so far, do not allow holes while extending 
//-----------------------------------------------------------------------------
	if (dc->fFirstStation != i) break;
      }

      last = dc->fLastStation;
      for (int i=last+1; i<kNStations; i++) {
//-----------------------------------------------------------------------------
// skip empty stations
//-----------------------------------------------------------------------------
	if (_data.stationUsed[i] == 0) continue;
	dc->fT0Min[i] = dc->fT0Min[dc->fLastStation]-_maxDtDs*(i-dc->fLastStation);
	dc->fT0Max[i] = dc->fT0Max[dc->fLastStation]+_maxDtDs*(i-dc->fLastStation);
	recoverStation(dc,i);
//-----------------------------------------------------------------------------
// so far, do not allow holes while extending 
//-----------------------------------------------------------------------------
	if (dc->fLastStation != i) break;
      }
    }

    return 0;
  }