G4String findStepStoppingProcessName(G4Step const* const aStep){

      G4VProcess const* process = aStep->GetPostStepPoint()->GetProcessDefinedStep();

      if (process) {

        return process->GetProcessName();

      } else {
        static bool printItOnce = true;
        if (printItOnce) {
          printItOnce = false;
          printProcessNotSpecifiedWarning(aStep->GetTrack());
        }
        static bool printItOnce2 = true;
        if (printItOnce2 && !printItOnce) {
          printItOnce2 = false;
          cout << __func__ << " The above message will not be repeated " << endl;
        }
        //        static const G4String pname = G4String("NotSpecified");
        return G4String("NotSpecified");

      }

    }