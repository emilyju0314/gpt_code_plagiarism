G4String findTrackStoppingProcessName(G4Track const* const trk){

      // First check to see if Mu2e code killed this track.
      G4VUserTrackInformation* info = trk->GetUserInformation();
      Mu2eG4UserTrackInformation const* tinfo   = dynamic_cast<Mu2eG4UserTrackInformation*>(info);

      if ( tinfo->isForced() ){
        return tinfo->code().name();
      }

      // Otherwise, G4 killed this track.
      return findStepStoppingProcessName(trk->GetStep());

    }