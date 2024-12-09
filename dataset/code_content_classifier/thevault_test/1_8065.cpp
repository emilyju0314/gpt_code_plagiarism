bool CalHelixFinderAlg::findHelix(CalHelixFinderData& Helix) {

    // fTimeCluster = TimePeak;
    //check presence of a cluster
    // const CaloCluster* cl = TimePeak->caloCluster().get();
    // if (cl == NULL)   return false;

    // //fill the calorimeter cluster info
    // Hep3Vector         gpos = _calorimeter->geomUtil().diskToMu2e(cl->diskID(),cl->cog3Vector());
    // Hep3Vector         tpos = _calorimeter->geomUtil().mu2eToTracker(gpos);
    // fCaloTime = cl->time();
    // fCaloX    = tpos.x();
    // fCaloY    = tpos.y();
    // fCaloZ    = tpos.z();
//-----------------------------------------------------------------------------
//  compute the allowed radial range for this fit
//-----------------------------------------------------------------------------
    float pb = fabs((CLHEP::c_light*1e-3)/(bz()*Helix._tpart.charge()));
    _rmin = _pmin/(pb*sqrt(1.0+_tdmax*_tdmax));
    _rmax = _pmax/(pb*sqrt(1.0+_tdmin*_tdmin));
//-----------------------------------------------------------------------------
//  particle charge, field, and direction affect the pitch range
//-----------------------------------------------------------------------------
    _dfdzsign = Helix._helicity == Helicity::poshel ? 1 : -1;// copysign(1.0,-Helix._tpart.charge()*Helix._fdir.dzdt()*bz());
    
    _smax     = _dfdzsign/(_rmax*_tdmax);
    _smin     = _dfdzsign/(_rmin*_tdmin);

    _mpDfDz   = _dfdzsign*_absMpDfDz;
//-----------------------------------------------------------------------------
// call down
//-----------------------------------------------------------------------------
    bool retval = fitHelix(Helix);

    return retval;
  }