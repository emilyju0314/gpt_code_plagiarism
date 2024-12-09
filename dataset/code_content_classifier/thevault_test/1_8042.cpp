bool saveThisTrajectory(G4Track const* const trk, double pointTrajectoryMomentumCut){

      // This is a guess at what might be useful.  Feel free to improve it.
      // We might want to change the momentum cut depending on which volume
      // the track starts in.
      CLHEP::Hep3Vector const& mom = trk->GetMomentum();
      return ( mom.mag() > pointTrajectoryMomentumCut );

    }