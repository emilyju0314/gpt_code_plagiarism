bool RobustHelixFit::extractFZ0(RobustHelixFinderData& HelixData, float& fz0){
    // find phi at z intercept.  Use a histogram technique since phi looping
    // hasn't been resolved yet, and to avoid inefficiency at the phi wrapping edge
    ComboHit*      hitP1(0);
    RobustHelix& rhel         = HelixData._hseed._helix;
    int          nHits(HelixData._chHitsToProcess.size());

    _hphi.Reset();
    for (int f=0; f<nHits; ++f){
      hitP1 = &HelixData._chHitsToProcess[f];
      if (!use(*hitP1) )             continue;   
      
      float phiex = rhel.circleAzimuth(hitP1->pos().z());
      float dphi  = deltaPhi(phiex,hitP1->helixPhi());
      _hphi.Fill(dphi);
      _hphi.Fill(dphi-CLHEP::twopi);
      _hphi.Fill(dphi+CLHEP::twopi);
    }//end loop over the hits

    // take the average of the maximum bin +- 1
    int imax = _hphi.GetMaximumBin();
    unsigned count(0);

    for (int ibin=std::max((int)0,imax-1); ibin <= std::min((int)imax+1,(int)_nphibins); ++ibin)
      {
	count += _hphi.GetBinContent(ibin);
	fz0   += _hphi.GetBinContent(ibin)*_hphi.GetBinCenter(ibin);
      }
     
    fz0 /= count;
    
    if (_diag){
      HelixData._diag.nfz0counter = count;
    }

    return (count >= _minnphi);
  }