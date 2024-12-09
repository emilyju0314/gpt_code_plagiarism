ProcessCode findCreationCode(G4Track const* const trk){
      G4VProcess const* process = trk->GetCreatorProcess();

      // If there is no creator process, then the G4Track was created by PrimaryGenerator action.
      if ( process == 0 ){
        return ProcessCode::mu2ePrimary;
      }

      // Extract the name from the process and look up the code.
      string name = process->GetProcessName();
      return ProcessCode::findByName(name);
    }