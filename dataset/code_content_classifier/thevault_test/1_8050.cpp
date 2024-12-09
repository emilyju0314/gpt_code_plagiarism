void Mu2eG4MT::produce(art::Event& event, art::ProcessingFrame const& procFrame) {

    int schedID = std::stoi(std::to_string(procFrame.scheduleID().id()));
    auto const tid = std::this_thread::get_id();

    WorkerRMMap::accessor access_workerMap;

    if (!myworkerRunManagerMap.find(access_workerMap, tid)){
      if (_mtDebugOutput > 0){
        G4cout << "FOR TID: " << tid << ", NO WORKER.  We are making one.\n";
      }
      myworkerRunManagerMap.insert(access_workerMap, tid);
      access_workerMap->second = std::make_unique<Mu2eG4WorkerRunManager>(conf_, ioconf_, tid);
    }

    if (event.id().event() == 1) {
      G4cout << "Our RMmap has " << myworkerRunManagerMap.size() << " members\n";
    }

    myworkerRunManagerMap.find(access_workerMap, tid);
    Mu2eG4WorkerRunManager* scheduleWorkerRM = (access_workerMap->second).get();
    access_workerMap.release();

    if (_mtDebugOutput > 1){
      G4cout << "FOR SchedID: " << schedID << ", TID=" << tid << ", workerRunManagers[schedID].get() is:" << scheduleWorkerRM << "\n";
    }

    //if this is the first time the thread is being used, it should be initialized
    if (!scheduleWorkerRM->workerRMInitialized()){
      scheduleWorkerRM->initializeThread(masterThread->masterRunManagerPtr(), originInWorld);
      scheduleWorkerRM->initializeRun(&event);
    }

    Mu2eG4PerThreadStorage* perThreadStore = scheduleWorkerRM->getMu2eG4PerThreadStorage();
    perThreadStore->initializeEventInfo(&event, simStage_);
    scheduleWorkerRM->processEvent(event.id());

    if (_mtDebugOutput > 2){
      G4cout << "Current Event in RM is: " << scheduleWorkerRM->GetCurrentEvent()->GetEventID() << "\n";
    }

    /////////////////////////////////////////////////////////////////////////////////////
    //putting data into the event

    if(!perThreadStore->eventPassed()) {
      perThreadStore->clearData();
      numExcludedEvents++;
    }
    else {
      perThreadStore->putDataIntoEvent();

      if(multiStagePars_.updateEventLevelVolumeInfos()) {
        const unsigned pvstage =
          writePhysicalVolumes(event,
                               multiStagePars_.updateEventLevelVolumeInfos()->input,
                               physVolHelper_.persistentSingleStageInfo(),
                               multiStagePars_.updateEventLevelVolumeInfos()->outInstance);

        if(pvstage != simStage_) {
          throw cet::exception("BADINPUT")
            << "Mu2eG4MT::produce() Error: inconsistent simStage: "
            <<simStage_<<" vs "<<pvstage<<"\n";
        }
      }
    }

    scheduleWorkerRM->TerminateOneEvent();

  }