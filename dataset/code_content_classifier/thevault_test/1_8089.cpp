void CompressionCheck0::analyze(const art::Event& event) {

    // Tracker
    art::Handle<StepPointMCCollection> tsteps1;
    event.getByLabel(trackerTag1_, tsteps1);
    auto tsteps2 = event.getValidHandle<StepPointMCCollection>(trackerTag2_);

    if ( tsteps1.isValid() ) {
      hTrackerSteps1_->Fill( tsteps1->size() );
      hTrackerStepsD_->Fill( tsteps2->size()-tsteps1->size() );
    }
    hTrackerSteps2_->Fill( tsteps2->size() );

    // Calorimeter
    art::Handle<StepPointMCCollection> csteps1;
    event.getByLabel(caloTag1_, csteps1);
    auto csteps2 = event.getValidHandle<StepPointMCCollection>(caloTag2_);

    if ( csteps1.isValid() ) {
      hCaloSteps1_->Fill( csteps1->size() );
      hCaloStepsD_->Fill( csteps2->size()-csteps1->size() );
    }
    hCaloSteps2_->Fill( csteps2->size() );

    // Calorimeter readout
    art::Handle<StepPointMCCollection> rsteps1;
    event.getByLabel(croTag1_, rsteps1);
    auto rsteps2 = event.getValidHandle<StepPointMCCollection>(croTag2_);

    if ( rsteps1.isValid() ) {
      hcroSteps1_->Fill( rsteps1->size() );
      hcroStepsD_->Fill( rsteps2->size()-rsteps1->size() );
    }
    hcroSteps2_->Fill( rsteps2->size() );

    // Virtual detector
    art::Handle<StepPointMCCollection> vsteps1;
    event.getByLabel(vdTag1_, vsteps1);
    auto vsteps2 = event.getValidHandle<StepPointMCCollection>(vdTag2_);

    if ( vsteps1.isValid() ) {
      hvdSteps1_->Fill( vsteps1->size() );
    }
    hvdSteps2_->Fill( vsteps2->size() );

    // SimParticles
    art::Handle<SimParticleCollection> sims1;
    event.getByLabel( simsTag1_, sims1);
    auto sims2 = event.getValidHandle<SimParticleCollection>( simsTag2_);

    if ( sims1.isValid() ){
      hnSims1_->Fill(sims1->size());
    }
    hnSims2_->Fill(sims2->size());

  }