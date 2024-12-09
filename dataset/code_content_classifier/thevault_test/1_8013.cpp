void ParticleIDRead::analyze(const art::Event& event) {
//    cout << "Enter ParticleIDRead:: analyze: " << _verbosity << endl;

    _eventid++;

    art::Handle<PIDProductCollection> pidsHandle;
    event.getByLabel(_fitterModuleLabel,pidsHandle);
    PIDProductCollection const& pids = *pidsHandle;

    if ( _verbosity > 0 && _eventid <= _maxPrint ){
      cout << "ParticleIDRead  for event: " << event.id() << "  Number of pid objects: " << pids.size() << endl;
    }

    _trkid = -1;

    for ( size_t i=0; i< pids.size(); ++i ){
      _trkid = i;
      PIDProduct const& pid   = pids.at(i);

      if ( _verbosity > 1 && _eventid <= _maxPrint ){
        cout << "   PIDProduct: "
             << i            << " "
             << pid.GetTrkID() << " "
             << pid.GetResidualsSlope() << " "
             << pid.GetResidualsSlopeError() << " "
             << pid.GetLogEProb() << " "
             << pid.GetLogMProb() << " "
             << endl;
      }

    }

  }