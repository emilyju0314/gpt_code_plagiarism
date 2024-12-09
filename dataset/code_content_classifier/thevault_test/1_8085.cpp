int DeltaFinderAna::initMcDiag() {

    int n = _list_of_mc_particles.size();
    for (int i=0; i<n; i++) {
      McPart_t* p = _list_of_mc_particles.at(i);
      delete p;
    }

    _list_of_mc_particles.clear();

    _list_of_mc_hit_info.clear();

    _list_of_mc_hit_info.resize(_nsh);

    //    const StrawHit* hit0 = &_shcol->at(0);

    int delta_nhits_tot = 0;

    for (int i=0; i<_nsh; i++) {
      const StrawHit*     sh  = &_shcol->at(i);
      const StrawHitFlag* shf = &_shfcol->at(i);

      const mu2e::StrawDigiMC* mcdigi = &_mcdigis->at(i);

      const mu2e::StrawGasStep   *stmc;
      if (mcdigi->wireEndTime(mu2e::StrawEnd::cal) < mcdigi->wireEndTime(mu2e::StrawEnd::hv)) {
	stmc = mcdigi->strawGasStep(mu2e::StrawEnd::cal).get();
      }
      else {
	stmc = mcdigi->strawGasStep(mu2e::StrawEnd::hv ).get();
      }

      const mu2e::SimParticle* sim = &(*stmc->simParticle());

//-----------------------------------------------------------------------------
// search if this particle has already been registered
//-----------------------------------------------------------------------------
      McPart_t* mc = findParticle(sim);

      if (mc == NULL) {
					// add new particle
	mc = new McPart_t(sim);
	_list_of_mc_particles.push_back(mc);
      }
      mc->fListOfHits.push_back(sh);

      StrawId   shid  = sh->strawId();
      const Straw& straw = _tracker->getStraw(shid);
      int station = straw.id().getStation();
      if (station < mc->fFirstStation) mc->fFirstStation = station;
      if (station > mc->fLastStation ) mc->fLastStation  = station;

      if (sh->time() < mc->fTime) mc->fTime = sh->time();

      mc->fListOfFlags.push_back(shf);

      McHitInfo_t* mc_hit_info = &_list_of_mc_hit_info.at(i);

      mc_hit_info->fMc   = mc;
      mc_hit_info->fFlag = shf;

      int pdg_id = mc->fSim->pdgId();

      if      (pdg_id == 2212)   mc_hit_info->fType = 0;
      else if (pdg_id == 11  ) { 
	float mom = mc->Momentum();
	if      (mom <  20)      {
	  mc_hit_info->fType = 1;
	  delta_nhits_tot++;
	}
	else if (mom <  90)      mc_hit_info->fType = 2;
	else if (mom < 110)      mc_hit_info->fType = 3;
      }
      else                       mc_hit_info->fType = 4;

      int flagged_as_delta = shf->hasAnyProperty(StrawHitFlag::bkg);
	
      if (flagged_as_delta) fNHitsDeltaReco++;
    }

    return 0;
  }