void CalHelixFinderAlg::resetTrackParamters() {

    fUseDefaultDfDz = 0;
    _hphi0                  = -9999.;
//-----------------------------------------------------------------------------
// quality paramters used for doing comparison between several track candidates
//-----------------------------------------------------------------------------
    _hdfdz                  = _mpDfDz;
  }