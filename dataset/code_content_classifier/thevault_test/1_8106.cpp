void CorsikaBinaryDetail::managePrincipals ( int runNumber,
                                          int subRunNumber,
                                          int eventNumber,
                                          art::RunPrincipal*&    outR,
                                          art::SubRunPrincipal*& outSR,
                                          art::EventPrincipal*&  outE){

    art::Timestamp ts;

    art::SubRunID newID(runNumber, subRunNumber);

    if(newID != lastSubRunID_) {
      // art takes ownership of the object pointed to by outSR and will delete it at the appropriate time.
      outR = pm_.makeRunPrincipal(runNumber, ts);
      outSR = pm_.makeSubRunPrincipal(runNumber,
                                      subRunNumber,
                                      ts);

    }
    lastSubRunID_ = newID;

    // art takes ownership of the object pointed to by outE and will delete it at the appropriate time.
    outE = pm_.makeEventPrincipal(runNumber, subRunNumber, eventNumber, ts, false);

  }