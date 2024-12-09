float  CalHelixFinderAlg::calculateWeight(const mu2e::ComboHit& Hit      ,
					     const XYZVectorF&         HelCenter,
					     float                Radius   ) {

    float    transErr = 5./sqrt(12.);
    //scale the error based on the number of the strawHits that are within the mu2e::ComboHit
    if (Hit.nStrawHits() > 1) transErr *= 1.5;
    float    transErr2 = transErr*transErr;

    float x   = Hit.pos().x();
    float y   = Hit.pos().y();
    float dx  = x-HelCenter.x();
    float dy  = y-HelCenter.y();
    float dxn = dx*Hit._sdir.x()+dy*Hit._sdir.y();

    float costh2 = dxn*dxn/(dx*dx+dy*dy);
    float sinth2 = 1-costh2;

    float e2     = Hit.wireErr2()*sinth2+transErr2*costh2;
    float wt     = 1./e2;
                                                    // scale the weight for having chi2/ndof distribution peaking at 1
    wt *= _weightXY;

    return wt;
  }