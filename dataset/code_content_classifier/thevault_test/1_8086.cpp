int DeltaFinderAna::associateMcTruth() {
//-----------------------------------------------------------------------------
// for each MC electron calculate the number of reconstructed hits
//-----------------------------------------------------------------------------
    int nmc    = _list_of_mc_particles.size();

    StrawHitFlag        deltamask(StrawHitFlag::bkg);

    for (int i=0; i<nmc; i++) {
      McPart_t* mc    = _list_of_mc_particles.at(i);
      mc->fNHitsDelta = 0;
//-----------------------------------------------------------------------------
// loop over the hits of MC delta electron and calculate fraction of them 
// which have been tagged as the delta electron hits
//-----------------------------------------------------------------------------
      int nh = mc->fListOfHits.size();
      for (int ih=0; ih<nh; ih++) {
	const StrawHitFlag* flag = mc->fListOfFlags.at(ih);

	int flagged_as_delta = flag->hasAnyProperty(deltamask);

	if (flagged_as_delta) mc->fNHitsDelta += 1;
      }

      int pdg_id = mc->fSim->pdgId();
      
      if (pdg_id == 11  ) { 
	float mom = mc->Momentum();
	if (mom < 20)      {
//-----------------------------------------------------------------------------
// call this "a delta electron"
//-----------------------------------------------------------------------------
	  fNHitsDeltaTot += mc->NHits();
	}
      }
    }

    //    printf("DeltaFinderAna::associateMcTruth: fNHitsDeltaTot = %5i\n",fNHitsDeltaTot);

    return 0;
  }