void controlTrajectorySaving(G4Track const* const trk, int sizeLimit, int currentSize,
                                 double pointTrajectoryMomentumCut){

      // Do not add the trajectory if the corresponding SimParticle is missing or if it fails momentum cut

      bool keep = ( sizeLimit<=0 || currentSize<sizeLimit ) &&
        saveThisTrajectory(trk, pointTrajectoryMomentumCut);

      G4TrackingManager* trkmgr = G4EventManager::GetEventManager()->GetTrackingManager();
      trkmgr->SetStoreTrajectory(keep);

    }