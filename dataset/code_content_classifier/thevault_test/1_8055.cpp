void EventGenerator::beginRun( art::Run &run){

    static int ncalls(0);
    if ( ++ncalls > 1){
      mf::LogInfo("EventGenerator")
        << "EventGenerator does not change state at beginRun.  Hope that's OK.";
      return;
    }

    cout << "Event generator configuration file: "
         << _configfile
         << "\n"
         << endl;

    SimpleConfig config(_configfile, _allowReplacement, _messageOnReplacement, _messageOnDefault );
    checkConfig(config);

    if ( _printConfig ){
      config.print(cout,"EvtGen: ");
    }

    // Change this to modify rather than delete and make an new one??

    // Delete generators from the previous run.
    _generators.clear();

    // Which generators will we run?
    bool doParticleGun          = config.getBool( "particleGun.do",      false );
    bool doCosmicDYB            = config.getBool( "cosmicDYB.do",        false );
    bool doCosmicFromTH2        = config.getBool( "cosmicFromTH2.do",    false );
    bool doFromG4BLFile         = config.getBool( "fromG4BLFile.do",     false );
    bool doCaloCalibGun         = config.getBool( "caloCalibGun.do",     false );

    // Instantiate generators for this run.
    if ( doParticleGun)          _generators.push_back( GeneratorBasePtr( new ParticleGun(     _engine,  run, config)) );
    if ( doCosmicDYB)            _generators.push_back( GeneratorBasePtr( new CosmicDYB(       _engine,  run, config)) );
    if ( doCosmicFromTH2)        _generators.push_back( GeneratorBasePtr( new CosmicFromTH2(   _engine,  run, config)) );
    if ( doFromG4BLFile)         _generators.push_back( GeneratorBasePtr( new FromG4BLFile(    _engine,  run, config)) );
    if ( doCaloCalibGun)         _generators.push_back( GeneratorBasePtr( new CaloCalibGun(    _engine,  run, config)) );

    if ( _generators.size() == 0 ){
      mf::LogWarning("CONTROL")
        << "EventGenerator has no generators enabled. Hope that's OK.";
    }

    config.printAllSummaries( cout, _configStatsVerbosity, "EvtGen: ");

  }