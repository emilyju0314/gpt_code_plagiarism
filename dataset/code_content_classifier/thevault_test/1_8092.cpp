void Mu2eG4TrackingAction::saveSimParticleStart(const G4Track* trk){

    G4int trackingVerbosityLevel = fpTrackingManager->GetVerboseLevel();

    _currentSize += 1;

    if( _sizeLimit>0 && _currentSize>_sizeLimit ) {
      if( (_currentSize - _sizeLimit)==1 ) {
        mf::LogWarning("G4") << "Maximum number of particles reached in Mu2eG4TrackingAction: "
                             << _currentSize << endl;
        _overflowSimParticles = true;
      }
      return;
    }

    const key_type kid = perThreadObjects_->simParticleHelper->particleKeyFromG4TrackID(trk->GetTrackID());

    const int parentId = trk->GetParentID();

    art::Ptr<GenParticle> genPtr;
    art::Ptr<SimParticle> parentPtr;
    ProcessCode creationCode{ProcessCode::unknown};

    if(parentId == 0) { // primary
      const auto g4TrkID = trk->GetTrackID();
      genPtr = perThreadObjects_->simParticlePrimaryHelper->genParticlePtr(g4TrkID);
      parentPtr = perThreadObjects_->simParticlePrimaryHelper->simParticlePrimaryPtr(g4TrkID);

      const auto orig = perThreadObjects_->simParticlePrimaryHelper->getEntry(g4TrkID);
      // A particle that is a continuation of a particle from an earlier stage
      // in Mu2eG4 multistage jobs gets mu2ePrimary creation code.
      // The StageParticle case is different, it is treated more like
      // a custom physics process with a set of dedicated creation codes.

      if(auto stpart = std::get_if<const StageParticle*>(&orig)) {
        creationCode = (*stpart)->creationCode();
      }
      else {
        creationCode = ProcessCode::mu2ePrimary;
      }

    }
    else { // not a primary
      parentPtr = perThreadObjects_->simParticleHelper->particlePtrFromG4TrackID(parentId);

      // Find the physics process that created this track.
      creationCode = Mu2eG4UserHelpers::findCreationCode(trk);
      // we shall replace creationCode with muCapCode from Mu2eG4UserTrackInformation if needed/present

      if (creationCode==ProcessCode(ProcessCode::muMinusCaptureAtRest)) {

        if ( trackingVerbosityLevel > 0 ) {
          G4cout << __func__
                 << " particle created by " << creationCode.name()
                 << " will try to replace the creation code "
                 << G4endl;

          G4VUserTrackInformation* tui = trk->GetUserInformation();
          if (tui) {
            G4cout << __func__
                   << " the track is labeled as " << tui->GetType()
                   << G4endl;
            G4cout << __func__
                   << " muCapCode is: "
                   << (dynamic_cast<Mu2eG4UserTrackInformation*>(tui))->muCapCode()
                   << G4endl;
          }
        }

        ProcessCode utic =
          (dynamic_cast<Mu2eG4UserTrackInformation*>(trk->GetUserInformation()))->muCapCode();
        if (utic!=ProcessCode(ProcessCode::unknown)) {
          creationCode=utic;
        }
      }
    } // else - not a primary


    if ( trackingVerbosityLevel > 0 ) {
      G4cout << __func__
             << " saving particle "
             << trk->GetParticleDefinition()->GetPDGEncoding()
             << ", "
             << trk->GetParticleDefinition()->GetParticleName()
             << " created by " << creationCode.name()
             << " with kinetic energy " << fixed << setw(8) << trk->GetKineticEnergy()
             << " with tot energy " << fixed << setw(8) << trk->GetTotalEnergy();
      if (trk->GetTouchable()) {
        G4cout << " in " << trk->GetTouchable()->GetVolume()->GetName()
               << " material " << trk->GetTouchable()->GetVolume()->GetLogicalVolume()->GetMaterial()->GetName()
               << " material cuts index "
               << trk->GetTouchable()->GetVolume()->GetLogicalVolume()->GetMaterialCutsCouple()->GetIndex();
      }
      G4cout << G4endl; // step related info is not available at this stage
    }

    // Track should not yet be in the map.  Add a debug clause to skip this test?
    if ( _transientMap.find(kid) != _transientMap.end() ){
      throw cet::exception("RANGE")
        << "SimParticle already in the event.  This should never happen. id is: "
        << kid
        << "\n";
    }

    // Add this track to the transient data.
    CLHEP::HepLorentzVector p4(trk->GetMomentum(),trk->GetTotalEnergy());

    PDGCode::type ppdgId = static_cast<PDGCode::type>(trk->GetDefinition()->GetPDGEncoding());

    // printing ions
    if ( trackingVerbosityLevel > 0 && ppdgId>PDGCode::G4Threshold ) {
      G4cout << __func__ << " Ion pdgid:          "
             << ppdgId
             << G4endl;
      const G4ParticleDefinition* pDef = trk->GetDefinition();
      pDef->DumpTable();
      // print data specific to ions
      // Get excitation energy of nucleus
      // Charge
      // Get Isomer level (=0 for ground state)
      const G4Ions* pG4Ion = dynamic_cast<const G4Ions*>(pDef);
      G4int flbi = pG4Ion->GetFloatLevelBaseIndex();
      G4cout << __func__ << " Ion specific data:  "
             << pG4Ion->GetExcitationEnergy()
             << ", " << pG4Ion->GetPDGCharge()
             << ", " << pG4Ion->GetIsomerLevel()
             << ", " << flbi
        //   << ", " << static_cast<G4int>(pG4Ion->GetFloatLevelBase())
             << ", " << G4String(G4Ions::FloatLevelBaseChar(G4Ions::FloatLevelBase(flbi)))
        //   << ", " << G4String(G4Ions::FloatLevelBaseChar(pG4Ion->GetFloatLevelBase()))
             << G4endl;
      Mu2eG4UserHelpers::printTrackInfo( trk, " Ion:          ", _transientMap,
                                         _timer, _mu2eOrigin);
    }

    // extracting info specific to ions
    SimParticle::IonDetail ion;
    if ( ppdgId>PDGCode::G4Threshold ) {
      const G4ParticleDefinition* pDef = trk->GetDefinition();
      ion.excitationEnergy = dynamic_cast<const G4Ions*>(pDef)->GetExcitationEnergy();
      ion.floatLevelBaseIndex = dynamic_cast<const G4Ions*>(pDef)->GetFloatLevelBaseIndex();
    }

    _transientMap.insert(std::make_pair(kid,SimParticle( kid,
                                                         perThreadObjects_->simParticleHelper->simStage(),
                                                         parentPtr,
                                                         ppdgId,
                                                         genPtr,
                                                         trk->GetPosition()-_mu2eOrigin,
                                                         p4,
                                                         trk->GetGlobalTime(),
                                                         trk->GetProperTime(),
                                                         _physVolHelper->index(trk),
                                                         trk->GetTrackStatus(),
                                                         creationCode,
                                                         ion)));

    // If this track has a parent, tell the parent about this track.
    if ( parentPtr.isNonnull() ){
      map_type::iterator i(_transientMap.find(SimParticleCollection::key_type(parentPtr.key())));
      if ( i == _transientMap.end() ){
        throw cet::exception("RANGE")
          << "Could not find parent SimParticle in " << __func__ << ".  id: "
          << parentPtr.key()
          << "\n";
      }
      i->second.addDaughter(perThreadObjects_->simParticleHelper->particlePtr(trk));

      // // print parent of an ion
      //
      // int parPDGId = i->second.pdgId();
      // if ( ppdgId >PDGCode::G4Threshold ) {
      //   G4String pName = "";
      //   if ( parPDGId >PDGCode::G4Threshold ) {
      //     G4cout << __func__ << " Parent base ion pdgid: " << parPDGId-parPDGId%10 << G4endl;
      //     G4ParticleDefinition* ion = G4IonTable::GetIonTable()->GetIon(parPDGId-parPDGId%10);
      //     pName = (ion) ? ion->GetParticleName() : "Unknown";
      //   } else {
      //     pName = G4ParticleTable::GetParticleTable()->FindParticle(parPDGId)->GetParticleName();
      //   }
      //   G4cout << __func__ << " Ion parent with approximate name : "
      //          << i->second.id()
      //          << ", " << parPDGId
      //          << ", " << pName
      //          << ", created by " << i->second.creationCode().name()
      //          << ", stopped by " << i->second.stoppingCode().name()
      //          << G4endl;
      // }
      // // print if parent is an ion
      // if ( parPDGId)) {
      //   G4cout << __func__ << " Ion daughter pdgid: " << ppdgId << G4endl;
      //   Mu2eG4UserHelpers::printTrackInfo( trk, "ion daughter: ", _transientMap,
      //                                      _timer, _mu2eOrigin);
      // }
    }
  }