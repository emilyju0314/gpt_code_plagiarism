void Mu2eG4TrackingAction::swapTrajectory(const G4Track* trk){

    key_type kid(perThreadObjects_->simParticleHelper->particleKeyFromG4TrackID(trk->GetTrackID()));

    const auto& trajectory = _steppingAction->trajectory();
    if ( int(trajectory.size()) < _mcTrajectoryMinSteps ) return;

    // Find the particle in the map.
    map_type::iterator i(_transientMap.find(kid));
    if ( i == _transientMap.end() ){
      G4Event const* event = G4RunManager::GetRunManager()->GetCurrentEvent();

      mf::LogWarning("G4") << "Mu2eG4TrackingAction::swapTrajectory: "
                           << "SimParticle is not found.\nprobably the SimParticleCollection exceeds its maximum allowed size."
                           << "Will not store MCTrajectory for: event "
                           << event->GetEventID()
                           << " Track: " << trk->GetTrackID() << "\n";
      return;
    }

    CLHEP::HepLorentzVector const& p0 = i->second.startMomentum();
    if ( p0.vect().mag() < _mcTrajectoryMomentumCut ) return;

    art::Ptr<SimParticle> sim = perThreadObjects_->simParticleHelper->particlePtr(trk);

    // Default construct the trajectory object in the output data product.
    auto retval = perThreadObjects_->mcTrajectories->insert( MCTrajectoryCollection::value_type( sim, MCTrajectory(sim) ));

    if ( !retval.second ){
      throw cet::exception("RANGE")
        << "In Mu2eG4TrackingAction::addTrajectory the MCTrajectory was already present for id: "
        << kid
        << "\n";
    }

    // The data product takes ownership of the array of points that was created in SteppingAction.
    // This leaves SteppingAction with an empty array.
    MCTrajectory& traj = retval.first->second;
    _steppingAction->swapTrajectory( traj.points() );

    // So far the trajectory holds the starting point of each step.
    // Add the end point of the last step.
    traj.points().emplace_back( trk->GetPosition()-_mu2eOrigin, trk->GetGlobalTime(), trk->GetKineticEnergy() );

  }