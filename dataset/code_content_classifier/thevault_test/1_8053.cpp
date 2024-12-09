void TrackerPrototypeDataDetail::managePrincipals ( int runNumber,
      int subRunNumber,
      int eventNumber,
      art::RunPrincipal*&    outR,
      art::SubRunPrincipal*& outSR,
      art::EventPrincipal*&  outE){

    art::Timestamp ts;

    if (currentEvent == printAtEvent){
      std::cout << "Event " << currentEvent << std::endl;
      printAtEvent = (printAtEvent+1)*2-1;
    }
    currentEvent++;


    if (first_call){
      outR = pm_.makeRunPrincipal(runNumber, ts);
      first_call = false;
    }
    art::SubRunID newID(runNumber, subRunNumber);

    if(newID != lastSubRunID_) {
      std::cout << "Subrun " << subRunNumber << std::endl;
      // art takes ownership of the object pointed to by outSR and will delete it at the appropriate time.
      outSR = pm_.makeSubRunPrincipal(runNumber,
          subRunNumber,
          ts);

    }
    lastSubRunID_ = newID;

    // art takes ownership of the object pointed to by outE and will delete it at the appropriate time.
    outE = pm_.makeEventPrincipal(runNumber, subRunNumber, eventNumber, ts, false);

  }