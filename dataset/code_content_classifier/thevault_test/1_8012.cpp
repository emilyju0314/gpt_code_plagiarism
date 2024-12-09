int CalHelixFinderDiag::fillHistograms(void * Data, int Mode) {

    _data = (Data_t*) Data;

    int en = _data->event->event();
    if ( en == _event_number) return -1;

    if (_first_call == 1) {
      _timeOffsets = new SimParticleTimeOffset(*_data->timeOffsets);
      _first_call = 0;
    }
    
    _event_number = en;
    _timeOffsets->updateMap(*_data->event);
//-----------------------------------------------------------------------------
// this part is so far simple
//-----------------------------------------------------------------------------
    _hist.nTimePeaks->Fill(_data->nTimePeaks);
    _hist.nseeds[0]->Fill(_data->nseeds[0]);
    _hist.nseeds[1]->Fill(_data->nseeds[1]);

    for (int i=0; i<_data->nseeds[0]; i++) {
      _hist.ntclhits[0]->Fill(_data->ntclhits[i]);
      _hist.nhits   ->Fill(_data->nhits   [i]);
      for (int j=0; j<_data->nhits   [i]; ++j){
	_hist.drVsDzSeed[0]->Fill(_data->hitDzSeed[i][j], _data->hitDrPred[i][j]);
      }
      _hist.p[0]->Fill(_data->p[i]);
      _hist.pT[0]->Fill(_data->pT[i]);
      _hist.radius[0]->Fill(_data->radius[i]);
      _hist.chi2XY[0]->Fill(_data->chi2XY[i]);
      _hist.chi2ZPhi[0]->Fill(_data->chi2ZPhi[i]);
      _hist.dr[0]->Fill(_data->dr[i]);
      _hist.shmeanr[0]->Fill(_data->shmeanr[i]);
      _hist.chi2d_helix[0]->Fill(_data->chi2d_helix[i]);
      _hist.loopId     [0]->Fill(_data->loopId[i]);
      if (_data->loopId[i] == 1){
	_hist.chi2d_loop0 [0]->Fill(_data->chi2d_loop0[i]);
	_hist.chi2d_line_loop0 [0]->Fill(_data->chi2d_line_loop0[i]);
	_hist.npoints_loop0  ->Fill(_data->npoints_loop0[i]);
      }
      if (_data->loopId[i] == 2) {
	_hist.chi2d_loop1 [0]->Fill(_data->chi2d_loop1[i]);
	_hist.chi2d_line_loop1 [0]->Fill(_data->chi2d_line_loop1[i]);
	_hist.npoints_loop1  ->Fill(_data->npoints_loop1[i]);	
      }

      if (_data->good[i] != 0) {
	_hist.ntclhits[1]->Fill(_data->ntclhits[i]);
	_hist.loopId  [1]->Fill(_data->loopId[i]);
	_hist.p       [1]->Fill(_data->p[i]);
	_hist.pT      [1]->Fill(_data->pT[i]);
	_hist.radius  [1]->Fill(_data->radius[i]);
	_hist.chi2XY  [1]->Fill(_data->chi2XY[i]);
	_hist.chi2ZPhi[1]->Fill(_data->chi2ZPhi[i]);
	_hist.dr      [1]->Fill(_data->dr[i]);
	_hist.shmeanr [1]->Fill(_data->shmeanr[i]);
	_hist.chi2d_helix[1]->Fill(_data->chi2d_helix[i]);
	if (_data->loopId[i] == 1) {
	  _hist.chi2d_loop0   [1]->Fill(_data->chi2d_loop0[i]);
	}
	if (_data->loopId[i] == 2) {
	  _hist.chi2d_loop1   [1]->Fill(_data->chi2d_loop1[i]);
	}
	
	for (int j=0; j<_data->nhits   [i]; ++j){
	_hist.drVsDzSeed[1]->Fill(_data->hitDzSeed[i][j], _data->hitDrPred[i][j]);
      }
      }

      _hist.nhitsvspT ->Fill(_data->nhits[i],_data->pT[i]);
      _hist.nhitsvsp  ->Fill(_data->nhits[i],_data->p [i]);

      _hist.nStationPairs->Fill(_data->nStationPairs[i]);
    }

    return 0;
  }