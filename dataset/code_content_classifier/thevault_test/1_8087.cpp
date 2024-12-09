void DeltaFinderAna::debug() {
//-----------------------------------------------------------------------------
// print MC electrons
//-----------------------------------------------------------------------------
    if (_printElectrons) {
      int nmc = _list_of_mc_particles.size();

      for (int i=0; i<nmc; i++) {
	McPart_t* mc = _list_of_mc_particles.at(i);
	const SimParticle* sim = mc->fSim;

	if ((sim->pdgId() == 11) && (mc->Time() > 550) && (mc->NHits()  >= _printElectronsMinNHits)) {

	  float fr = mc->fNHitsDelta/(mc->NHits()+1.e-3);

	  if (fr < _printElectronsMaxFReco) {

	    printf(" electron: sim.id = %10li mom = %10.3f time= %9.3f nhits = %3i nhits(delta): %3i first: %2i last: %2i",
		   sim->id().asInt(), mc->Momentum(), mc->Time(), 
		   mc->NHits(), 
		   mc->fNHitsDelta, 
		   mc->fFirstStation, mc->fLastStation);
	    printf(" fraction: %6.3f\n",fr);
	  }
	}
      }
    }
  }