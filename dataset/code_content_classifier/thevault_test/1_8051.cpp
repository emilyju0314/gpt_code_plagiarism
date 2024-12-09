void Mu2eG4MT::endRun(art::Run & run, art::ProcessingFrame const& procFrame) {

    if (_mtDebugOutput > 0){
      G4cout << "At endRun pt1, we have " << myworkerRunManagerMap.size() << " members in the map "
             << "and are running " << num_threads << " threads.\n" ;
    }
    else if (num_threads < static_cast <int> (myworkerRunManagerMap.size()) && _mtDebugOutput > 0){
      G4cout << "At endRun pt1, we have " << myworkerRunManagerMap.size() << " members in the map "
             << "and are running " << num_threads << " threads.\n" ;
    }


    if (storePhysicsTablesDir_!="") {
      if ( _rmvlevel > 0 ) {
        G4cout << __func__ << " Will write out physics tables to "
               << storePhysicsTablesDir_
               << G4endl;
      }
      masterThread->masterRunManagerPtr()->getMasterPhysicsList()->StorePhysicsTable(storePhysicsTablesDir_);
    }

    std::atomic<int> threads_left = num_threads;
    tbb::task_group g;
    for (int i = 0; i < num_threads; ++i) {

      auto destroy_worker = [&threads_left, i, this] {
        WorkerRMMap::accessor access_workerMap;
        std::thread::id this_tid = std::this_thread::get_id();

        if (myworkerRunManagerMap.find(access_workerMap, this_tid)) {
          access_workerMap->second.reset();
          myworkerRunManagerMap.erase(access_workerMap);
        }

        access_workerMap.release();
        --threads_left;
        while (threads_left != 0) {}
        return;
      };
      g.run(destroy_worker);
    }//for
    g.wait();

    if (_mtDebugOutput > 0){
      G4cout << "At endRun pt2, we have " << myworkerRunManagerMap.size() << " members in the map.\n";
    }

    //This cleans up the worker run managers that are in threads no longer being used, i.e. 'transient threads'
    WorkerRMMap::iterator it = myworkerRunManagerMap.begin();
    while (it != myworkerRunManagerMap.end()) {
      if (_mtDebugOutput > 0){
        std::cout << "releasing RM for thread ID" << it->first << std::endl;
      }
      it->second.release();
      ++it;
    }

    G4cout << "at endRun: numExcludedEvents = " << numExcludedEvents << G4endl;
    myworkerRunManagerMap.clear();
    masterThread->endRun();
  }