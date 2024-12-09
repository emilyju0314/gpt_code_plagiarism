void CosmicFilter::beginJob(){

    art::ServiceHandle<art::TFileService> tfs;

    _hist.fTrackD0     = tfs->make<TH1F>("trk_d0"  ,"Track D0"       ,500, -500., 500.);
    _hist.fNTracks     = tfs->make<TH1F>("ntrk"    ,"N(tracks)"      ,100,    0., 100.);
    _hist.fNGoodTracks = tfs->make<TH1F>("ngtrk"   ,"N(good tracks)" ,100,    0., 100.);
    _hist.fTrackZ0[0]  = tfs->make<TH1F>("trk_z0_0","Track Z0[0]"    ,500,-2500.,2500.);
    _hist.fTrackZ0[1]  = tfs->make<TH1F>("trk_z0_1","Track Z0[1]"    ,500,-2500.,2500.);
    _hist.fP           = tfs->make<TH1F>("p"       ,"Track Mom (S=0)",200,    0., 400.);
  }