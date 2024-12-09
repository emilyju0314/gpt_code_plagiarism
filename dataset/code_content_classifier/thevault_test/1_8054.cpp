bool EventGenerator::checkForG4blFile(){
    SimpleConfig config(_configfile, true, false, false );

    // At the present time the only code that produces G4BeamlineInfo
    // is the FromG4BLFile option.
    return config.getBool( "fromG4BLFile.do", false );
  }