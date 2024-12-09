VDHit(const ExtMonFNALPlaneStack& det, const StepPointMC& hit)
        : pmag(hit.momentum().mag())
        , px(), py(), pz(), x(), y(), z()
        , time(hit.time())
        , charge(getCharge(hit.simParticle()->pdgId()))
        , pdgId(hit.simParticle()->pdgId())
        , particleId(hit.simParticle()->id().asUint())
      {
        const CLHEP::Hep3Vector p = det.mu2eToStack_momentum(hit.momentum());
        px = p.x();
        py = p.y();
        pz = p.z();

        const CLHEP::Hep3Vector v = det.mu2eToStack_position(hit.position());
        x = v.x();
        y = v.y();
        z = v.z();
      }