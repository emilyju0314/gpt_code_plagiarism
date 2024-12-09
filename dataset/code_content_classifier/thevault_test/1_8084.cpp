void Mu2eG4::produce(art::Event& event) {

    perThreadStore.initializeEventInfo(&event, simStage_);

    if(multiStagePars_.updateEventLevelVolumeInfos()) {
      const unsigned pvstage =
        writePhysicalVolumes(event,
                             multiStagePars_.updateEventLevelVolumeInfos()->input,
                             _physVolHelper.persistentSingleStageInfo(),
                             multiStagePars_.updateEventLevelVolumeInfos()->outInstance);

      if(pvstage != simStage_) {
        throw cet::exception("BADINPUT")
          << "Mu2eG4::produce() Error: inconsistent simStage: "
          <<simStage_<<" vs "<<pvstage<<"\n";
      }
    }

    // Run G4 for this event and access the completed event.
    BeamOnDoOneArtEvent( event.id().event() );

    if(!perThreadStore.eventPassed()) {
      perThreadStore.clearData();
      numExcludedEvents++;
    }
    else {
      perThreadStore.putDataIntoEvent();
    }

    _runManager->TerminateOneEvent();
  }