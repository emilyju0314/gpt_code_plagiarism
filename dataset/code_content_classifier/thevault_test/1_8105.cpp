GenParticle( PDGCode::type pdgId,
                 GenId::enum_type generatorId,
                 CLHEP::Hep3Vector const&       position,
                 CLHEP::HepLorentzVector const& momentum,
                 double time,
                 double properTime = 0.):
      _pdgId(pdgId),
      _generatorId(GenId(generatorId)),
      _position(position),
      _momentum(momentum),
      _time(time),
      _properTime(properTime)
    {}