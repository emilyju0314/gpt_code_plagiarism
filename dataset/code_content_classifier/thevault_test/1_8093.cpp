void Mu2eG4TrackingAction::saveSimParticleEnd(const G4Track* trk){

    if( _sizeLimit>0 && _currentSize>=_sizeLimit ) return;

    G4int trackingVerbosityLevel = fpTrackingManager->GetVerboseLevel();

    key_type kid(perThreadObjects_->simParticleHelper->particleKeyFromG4TrackID(trk->GetTrackID()));

    // Find the particle in the map.
    map_type::iterator i(_transientMap.find(kid));
    if ( i == _transientMap.end() ){
      throw cet::exception("RANGE")
        << "Could not find existing SimParticle in Mu2eG4TrackingAction::saveSimParticleEnd()  id: "
        << kid
        << "\n";
    }

    // Reason why tracking stopped, decay, range out, etc.
    G4String pname  = Mu2eG4UserHelpers::findTrackStoppingProcessName(trk);

    // adjust verbosity for isTrackKilledByFieldPropagator
    int trVerbosity = trackingVerbosityLevel;
    if ( _stepLimitKillerVerbose && trVerbosity < 1 ) trVerbosity = 1;

    if (pname == "Transportation" &&
        Mu2eG4UserHelpers::isTrackKilledByFieldPropagator(trk, trVerbosity)) {
      pname = G4String("mu2eFieldPropagator");
      if ( !(trk->GetDefinition()->GetPDGEncoding() == 11 || // electron & proton codes hardcoded for now
             trk->GetDefinition()->GetPDGEncoding() == 2212 ) ||
           G4LossTableManager::Instance()->
           GetRange(trk->GetDefinition(),
                    trk->GetKineticEnergy(),
                    trk->GetStep()->GetPreStepPoint()->GetMaterialCutsCouple())>_rangeToIgnore) {
        // count non electrons/protons or electrons/protons which have a range which is likely to make them travel
        ++_nKilledByFieldPropagator;
      }

    }

    if ( pname == "mu2eSpecialCutsProcess"
         && trk->GetCurrentStepNumber() >= static_cast<int>(_mu2elimits.maxStepsPerTrack())) {
      if ( _stepLimitKillerVerbose ) {
        G4cout << __func__ << " WARNING: kill particle in "
               << trk->GetStep()->GetPreStepPoint()->
          GetPhysicalVolume()->GetLogicalVolume()->GetName()
               << " due to large number of steps." << G4endl;
        Mu2eG4UserHelpers::printKilledTrackInfo(trk);
      }
      ++_numKilledTracks;

      // Changing the pname to the old name used in such cases
      pname = G4String("mu2eMaxSteps");

    }

    ProcessCode stoppingCode(_processInfo->findAndCount(pname));

    if (trackingVerbosityLevel > 0 ) {
      G4int prec = G4cout.precision(15);
      const G4DynamicParticle*  pParticle = trk->GetDynamicParticle();
      double theKEnergy  = pParticle->GetKineticEnergy();
      const G4ThreeVector& theMomentumDirection = pParticle->GetMomentumDirection();
      Mu2eG4UserTrackInformation* uti =
        (dynamic_cast<Mu2eG4UserTrackInformation*>(trk->GetUserInformation()));
      G4cout << __func__ << " KE before int " << uti->GetKineticEnergy()
             << " Momentum direction before int " << uti->GetMomentumDirection()
             << G4endl;
      G4cout << __func__ << " KE            " << theKEnergy
             << " Momentum direction            " << theMomentumDirection
             << G4endl;
      G4cout.precision(prec);
    }


    //Get kinematics just before annihilation
    double endKE = Mu2eG4UserHelpers::getEndKE(trk);
    CLHEP::HepLorentzVector endMomentum =  Mu2eG4UserHelpers::getEndMomentum(trk);

    //Get number od steps the track is made of
    int nSteps = Mu2eG4UserHelpers::getNSteps(trk);

    // Add info about the end of the track.  Throw if SimParticle not already there.
    i->second.addEndInfo( trk->GetPosition()-_mu2eOrigin,
                          endMomentum,
                          trk->GetGlobalTime(),
                          trk->GetProperTime(),
                          _physVolHelper->index(trk),
                          trk->GetTrackStatus(),
                          stoppingCode,
                          endKE,
                          nSteps,
                          trk->GetTrackLength()
                          );

    // the following is to establish for debugging if the parent pdgid to see if it is an ion
    // const int parentId = trk->GetParentID();
    // art::Ptr<SimParticle> parentPtr;
    // int parPDGId = 0;
    // if(parentId == 0) { // primary
    //   parentPtr = perThreadObjects_->simParticlePrimaryHelper->simParticlePrimaryPtr(trk->GetTrackID());
    // }
    // else { // not a primary
    //   parentPtr = perThreadObjects_->simParticleHelper->particlePtrFromG4TrackID(parentId);
    // }
    // if ( parentPtr.isNonnull() ){
    //   map_type::iterator i(_transientMap.find(SimParticleCollection::key_type(parentPtr.key())));
    //   if ( i == _transientMap.end() ){
    //     throw cet::exception("RANGE")
    //       << "Could not find parent SimParticle in " << __func__ << ".  id: "
    //       << parentPtr.key()
    //       << "\n";
    //   }
    //   parPDGId = i->second.pdgId();
    // }

    if ( trackingVerbosityLevel > 0
         // || trk->GetDefinition()->GetPDGEncoding()>PDGCode::G4Threshold
        ) {
      G4int prec = G4cout.precision(15);
      G4cout << __func__
             << " particle "
             << i->second.pdgId() << ", "
             << trk->GetParticleDefinition()->GetParticleName()
             << " stopped by " << stoppingCode // << ", " << pname
             << " totE deposit " << fixed << trk->GetStep()->GetTotalEnergyDeposit()
             << " NonIonE deposit " << fixed << trk->GetStep()->GetNonIonizingEnergyDeposit()
             << " in " << trk->GetVolume()->GetName()
             << " material " << trk->GetMaterial()->GetName()
             << " material cuts index " << trk->GetMaterialCutsCouple()->GetIndex()
             << G4endl;
      G4cout << __func__
             << " vertex KE " << trk->GetVertexKineticEnergy()
             << " vertex direction " << trk->GetVertexMomentumDirection()
             << G4endl;
      G4cout << __func__ << " track statuses: " << i->second.startG4Status()
             << ", " << i->second.endG4Status()
             << G4endl;
      G4cout << __func__
             << " step length " << trk->GetStepLength()
             << ", track length " << trk->GetTrackLength()
             << ", step number " << trk->GetCurrentStepNumber()
             << ", created by " << Mu2eG4UserHelpers::findCreationCode(trk)
             << G4endl;
      if ( trk->GetDefinition()->GetPDGEncoding()>PDGCode::G4Threshold ) {
        const G4Ions* pG4Ion = dynamic_cast<const G4Ions*>(trk->GetDefinition());
        G4int flbi = pG4Ion->GetFloatLevelBaseIndex();
        G4cout << __func__ << " Ion "
               << pG4Ion->GetParticleName()
               << " with excitaion energy: "
               << pG4Ion->GetExcitationEnergy()
               << " with float level base: "
               << G4String(G4Ions::FloatLevelBaseChar(G4Ions::FloatLevelBase(flbi))) << " " << flbi
               << G4endl;
      }
      G4cout.precision(prec);
    }
  }