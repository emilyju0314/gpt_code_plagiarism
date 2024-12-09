void EventGenerator::checkConfig( const SimpleConfig&  config){

    // The known cosmic ray generators.
    vector<string> keys;
    if ( keys.size() == 0 ){
      keys.push_back("cosmictoy.do");
      keys.push_back("cosmicDYB.do");
      keys.push_back("cosmic.do");
    }

    // Require that 0 or 1 of the generators to be present.
    requireUniqueKey( keys, config );

  }