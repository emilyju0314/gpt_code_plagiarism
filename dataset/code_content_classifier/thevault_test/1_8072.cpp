void CalHelixFinderAlg::addCaloClusterToFitPhiZ(CalHelixFinderData& Helix){
    float dfdz      = Helix._dfdz;
    float phi0      = Helix._fz0;
    XYZVectorF helCenter = Helix._center;
    if (Helix._sxy.qn() > 0) {
      helCenter = XYZVectorF( Helix._sxy.x0(), Helix._sxy.y0(), 0);
    }

    float zCl   = fCaloZ;
    float dx    = (fCaloX - helCenter.x());
    float dy    = (fCaloY - helCenter.y());
    float phiCl = polyAtan2(dy, dx);
    if (phiCl < 0) phiCl = phiCl + 2*M_PI;

    float deltaPhi = zCl*dfdz + phi0 - phiCl;
    while (deltaPhi > M_PI){
      phiCl   += 2*M_PI;
      deltaPhi = zCl*dfdz + phi0 - phiCl;
    }
    while (deltaPhi < -M_PI){
      phiCl   -= 2*M_PI;
      deltaPhi = zCl*dfdz + phi0 - phiCl;
    }
    
//check residual before adding to the LSqsum
    float xdphi  = fabs(deltaPhi)/_sigmaPhi;

// weight_cl of 10 corresponds to an uncertainty of 0.1 in phi(cluster),
// which means sigma(R-phi) of about 2-3 cm, about right
// hit weight is determined by the assumed phi error of _sigmaPhi=0.1
    if ( xdphi < 2.*_maxXDPhi ) {
      float weight_cl = 784.;//10.0; 
      Helix._szphi.addPoint(zCl,phiCl,weight_cl);
      Helix._nZPhiSh += 1;
    }
    
    if (_debug > 5) {
      printf("[CalHelixFinderAlg::doLinearFitPhiZ] %08x %2i %6i %3i %12.5f %12.5f %10.5f %10.3f %10.3f %10.3f %10.5f %10.5f %5.3f\n",
	     0, 1, 0, 0,  zCl, phiCl, deltaPhi, xdphi, 0., 0., dfdz, 0., 0.);
    }

  }