void CompressionCheck0::beginJob(){

    // Get a handle to the TFile service.
    art::ServiceHandle<art::TFileService> tfs;

    hTrackerSteps1_ = bookTH1F( *tfs, "trackerSteps1", "Tracker Steps Before", trackerStepBins_ );
    hTrackerSteps2_ = bookTH1F( *tfs, "trackerSteps2", "Tracker Steps After", trackerStepBins_ );
    hTrackerStepsD_ = tfs->make<TH1F>( "trackerStepsD", "Tracker Steps Delta",  3, -1.,   1. );

    hCaloSteps1_ = bookTH1F( *tfs, "caloSteps1", "Calo Steps Before",  caloStepBins_ );
    hCaloSteps2_ = bookTH1F( *tfs, "caloSteps2", "Calo Steps After",  caloStepBins_ );
    hCaloStepsD_ = tfs->make<TH1F>( "caloStepsD", "Calo Steps Delta",    3, -1.,   1. );

    hcroSteps1_ = bookTH1F( *tfs, "croSteps1", "Calo Readout Steps Before", croStepBins_ );
    hcroSteps2_ = bookTH1F( *tfs, "croSteps2", "Calo Readout Steps After", croStepBins_ );
    hcroStepsD_ = tfs->make<TH1F>( "croStepsD", "Calo Readout Steps Delta",    3, -1.,   1. );

    hvdSteps1_ = bookTH1F( *tfs, "vdSteps1", "vd Steps Before",  vdStepBins_ );
    hvdSteps2_ = bookTH1F( *tfs, "vdSteps2", "vd Steps After",   vdStepBins_ );

    hnSims1_ = bookTH1F( *tfs, "nSims1", "Number of SimParticles Before", simsBeforeBins_ );
    hnSims2_ = bookTH1F( *tfs, "nSims2", "Number of SimParticles After",  simsAfterBins_  );

  }