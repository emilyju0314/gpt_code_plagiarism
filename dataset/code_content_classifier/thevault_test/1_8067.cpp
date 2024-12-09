int CalHelixFinderAlg::findDfDz_1(CalHelixFinderData& Helix, HitInfo_t SeedIndex, int  Diag_flag) {

//     float phi, phi_ref(-1e10), z, z_ref, dphi, dz, dzOverHelPitch;

//     CLHEP::Hep3Vector* center = &Helix._center;
//     CLHEP::Hep3Vector pos_ref;

//     _hDfDzRes->Reset();
//     _hPhi0Res->Reset();
// 					// 2015 - 03 -30 G. Pezzu changed the value of tollMax.
// 					// using the initial value of dfdz we can set it more accuratelly:
// 					// tollMax = half-helix-step = Pi / dfdz
//     float tollMin(100.);
// //-----------------------------------------------------------------------------
// // 2017-09-26 gianipez fixed a bug: in case the Helix phi-z fit didn't converge yet, 
// // Helix._dfdz is set to -1e6, so we need to make a check here!
// // this is a tempOrary fix that doesn't take into account the particle helicity. FIX ME!
// //-----------------------------------------------------------------------------
//     float helix_dfdz(_mpDfDz);
//     // 2017-11-14 gianipez: findDfDz shoudl use the dfdz value obtained only from the linearFit
//     if (Helix._szphi.qn() >= 10) helix_dfdz = Helix._szphi.dfdz();
//     //    if (Helix._dfdz > 0) helix_dfdz =  Helix._dfdz;
//     float tollMax = 2.*M_PI / helix_dfdz; 

//     if (_debug > 5) {
//       printf("[CalHelixFinderAlg::findDfDz:BEGIN] x0 = %9.3f y0 = %9.3f Helix._radius = %9.3f",
// 	     center->x(), center->y(), Helix._radius);
//       printf("helix_dfdz = %9.6f Helix._nStrawHits = %3i tollMax = %8.6f\n",helix_dfdz, Helix._nStrawHits, tollMax);
//     }

//     int       nstations, nhits[30];
//     float    phiVec[30], zVec[30], weight(0), weight_cl(0);
//     PanelZ_t* panelz(0);

//     // np        = _xyzp.size();
//     nstations = _tracker->nStations();

//     for (int i=0; i<nstations; i++) {
//       phiVec[i] = 0;
//       zVec  [i] = 0;
//       nhits [i] = 0;
//     }
//     //-----------------------------------------------------------------------------
//     // Part 1: use only contiguous parts of the trajectory
//     //-----------------------------------------------------------------------------
//     for (int p=SeedIndex.Panel; p<FaceZ_t::kNTotalPanels; ++p){
//       panelz = &Helix._oTracker[p];
//       int  nhitsPerPanel  = panelz->fNHits;
//       int  seedPanelIndex(0);
//       if (nhitsPerPanel == 0)                                                            continue;
//       if (p==SeedIndex.Panel) seedPanelIndex = SeedIndex.PanelHitIndex;  

//       for (int i=seedPanelIndex; i<nhitsPerPanel; ++i){   
// 	mu2e::ComboHit* hit = &panelz->_chHitsToProcess.at(i);
// 	int index = p*FaceZ_t::kNMaxHitsPerPanel + i;
// 	if (Helix._hitsUsed[index] != 1)                     continue;

// 	int ist = hit->_straw->id().getStation();                   // station number
// 	phi     = polyAtan2(hit->y()-center->y(),hit->x()-center->x()); // atan2 returns its result in [-pi,pi], convert to [0,2pi]
// 	if (phi < 0) phi += 2*M_PI;
// 	zVec  [ist] += hit->z();
// 	//-----------------------------------------------------------------------------
// 	// make sure there all hits within the station get close values of phi, although a 
// 	// common 2pi ambiguity is still unresolved
// 	//-----------------------------------------------------------------------------
// 	if (nhits[ist] == 0) phiVec[ist] = phi;
// 	else {
// 	  while (phi-phiVec[ist] >  M_PI) phi -= 2*M_PI;
// 	  while (phi-phiVec[ist] < -M_PI) phi += 2*M_PI;
	
// 	  phiVec[ist] = (phiVec[ist]*nhits[ist]+phi)/(nhits[ist]+1);
// 	}
// 	nhits [ist] += 1;
//       }
//     }

//     for (int i=0; i<nstations; i++) {
//       if (nhits[i] > 0) {
// 	zVec  [i] = zVec  [i]/nhits[i];
//       }
//     }
    
//     if (_debug >5) {
//       printf("[CalHelixFinderAlg::findDfDz] StationID  nhits       z        phi\n");
//       for (int i=0; i<nstations; i++) {
// 	if (nhits[i] > 0) printf("[CalHelixFinderAlg::findDfDz] %5i %6i    %9.3f %8.5f\n", i,nhits[i],zVec[i],phiVec[i]);
//       }
//     }

//     int i0(-1), first_point(1);
// 					// add the cluster phi
//     float zCl   = fCaloZ;
//     float phiCl = polyAtan2(fCaloY-center->y(),fCaloX-center->x());
//     if (phiCl < 0) phiCl += 2*M_PI;

//     for (int i=0; i<nstations; i++) {
//       if (nhits[i] == 0)                                    continue; 
// 				        // i0: fist station with hits
//       if (first_point) {
// 	i0          = i;
// 	first_point = 0;
//       }

//       phi_ref = phiVec[i];
//       z_ref   = zVec  [i];

//       for(int j=i+1; j<nstations; ++j) {
// 	if (nhits[j] == 0)                                  continue;
// 	phi = phiVec[j];
// 	z   = zVec  [j];
// 	dz  = z - z_ref;
	
// 	dzOverHelPitch = dz/tollMax - int(dz/tollMax);
// 	weight         = nhits[i] + nhits[j];

// 	//	if ((phi_ref > -9999) && (dzOverHelPitch < _dzOverHelPitchCut) && (dz > tollMin)) {
// 	if (dz > tollMin) {
// 	  dphi = phi-phi_ref;
//  	  while (dphi >  M_PI) dphi -= 2*M_PI;
//  	  while (dphi < -M_PI) dphi += 2*M_PI;
// //-----------------------------------------------------------------------------
// // add 2*PI to take into account the fact we are in the second loop
// // FIX ME: what to do if we are in the third loop?
// //-----------------------------------------------------------------------------
// 	  if (dz > tollMax) dphi += 2*M_PI*int(dz/tollMax);

// 	  float dphidz = dphi/dz;
// 	  while (dphidz < 0.) {
// 	    dphi    = dphi+2.*M_PI;
// 	    dphidz  = dphi/dz;
// 	  }
// 	  _hDfDzRes->Fill(dphidz, weight);

// 	  float tmpphi0 = phi_ref - dphidz*z_ref;
// 	  tmpphi0        = TVector2::Phi_0_2pi(tmpphi0);

// 	  if (_debug > 5) {
// 	    printf("[CalHelixFinderAlg::findDfDz:1] z_ref: %9.3f z: %9.3f dz: %9.3f",z_ref,z,dz);
// 	    printf(" phi_ref: %9.5f phi: %9.5f dphi: %9.5f dz/HelPitch: %10.3f dphi/dz: %9.5f phi0 = %9.6f\n",
// 		   phi_ref,phi,dphi, dzOverHelPitch, dphidz, tmpphi0);
// 	  }
// //-----------------------------------------------------------------------------
// // in case dfdz is out of limits, set tmpphi0 as negative
// //-----------------------------------------------------------------------------
// 	  if ((dphidz < _minDfDz) || (dphidz >  _maxDfDz)) tmpphi0 = -1;
// 	  _hPhi0Res->Fill(tmpphi0, weight);
// 	}
//       }
// //-----------------------------------------------------------------------------
// // include the calorimeter cluster phi
// //-----------------------------------------------------------------------------
//       dz             = zCl - z_ref;
//       dzOverHelPitch = dz/tollMax - int(dz/tollMax);
//       weight_cl      =  nhits[i];

//       //      if ((dzOverHelPitch < _dzOverHelPitchCut) && (dz > tollMin)) {
//       if (dz > tollMin) {
// 	dphi  = phiCl - phi_ref;
// 	dphi  = TVector2::Phi_0_2pi(dphi);
// //-----------------------------------------------------------------------------
// // add 2 pi for taking into account the fact we are in the second loop
// // *FIX ME*: what if we are in the third loop?
// //-----------------------------------------------------------------------------
// 	if (dz > tollMax) dphi += 2*M_PI*int(dz/tollMax);

// 	float dphidz = dphi/dz;
// 	while (dphidz < 0.) {
// 	  dphi   += 2.*M_PI;
// 	  dphidz = dphi/dz;
// 	}

// 	float tmpphi0 = phi_ref - dphidz*z_ref;
// 	tmpphi0        = TVector2::Phi_0_2pi(tmpphi0);

// 	if (_debug > 5){
// 	  printf("[CalHelixFinderAlg::findDfDz:2] z_ref: %9.3f z: %9.3f dz: %9.3f",z_ref,zCl,dz);
// 	  printf(" phi_ref: %9.5f phi: %9.5f dphi: %9.5f dz/HelPitch: %10.3f dphi/dz: %9.5f phi0 = %9.6f\n",
// 		 phi_ref,phiCl,dphi, dzOverHelPitch, dphidz, tmpphi0);
// 	}

// 	if (dzOverHelPitch < _dzOverHelPitchCut ) {
// 	  _hDfDzRes->Fill(dphidz, weight_cl);
// 	  if ((dphidz < _minDfDz) || (dphidz >  _maxDfDz)) tmpphi0 = -1;
// 	  _hPhi0Res->Fill(tmpphi0, weight_cl);
// 	}
//       }
//     }
// //-----------------------------------------------------------------------------
// // 2015 - 04- 02 G. Pezzu changed the way the maximum is searched
// // since sometimes a 2pi ambiguity creates two peaks in the histogram
// // we want to use the second, because it is the correct one
// //-----------------------------------------------------------------------------
//     float  maxContent = _hDfDzRes->GetMaximum() - 0.001;
//     int      maxBin    = _hDfDzRes->FindLastBinAbove(maxContent);//GetMaximumBin();
//     _hdfdz             = _hDfDzRes->GetBinCenter(maxBin);//_hDfDzRes->GetMean();
//     float dfdzmean    = _hDfDzRes->GetMean();
//     int    nentries    = _hDfDzRes->GetEntries();
//     int    overflows   = _hDfDzRes->GetBinContent(0)  + _hDfDzRes->GetBinContent(_hDfDzRes->GetNbinsX()+1);

//     maxContent         = _hPhi0Res->GetMaximum() - 0.001;
//     maxBin             = _hPhi0Res->FindLastBinAbove(maxContent);//GetMaximumBin();

//     float mpvphi0     = _hPhi0Res->GetBinCenter(maxBin); //_hPhi0Res->GetMean();
//     float menaphi0    = _hPhi0Res->GetMean();
//     int    nentriesphi = _hPhi0Res->GetEntries();

//     _hphi0 = mpvphi0;  // 2018-01-05: *FLOAT_CHECK*

//     if (_debug > 5) {
//       printf("[CalHelixFinderAlg::findDfDz:DFDZ] nent: %3i mpvDfDz: %9.6f meanDphiDz: %9.6f under: %3.0f over: %3.0f ENTRIES:",
// 	     nentries, _hdfdz, dfdzmean,
// 	     _hDfDzRes->GetBinContent(0),_hDfDzRes->GetBinContent(_hDfDzRes->GetNbinsX()+1)
// 	     );
//       for (int i=0; i<_hDfDzRes->GetNbinsX(); i++) {
// 	printf(" %3.0f",_hDfDzRes->GetBinContent(i+1));
//       }
//       printf("\n");

//       printf("[CalHelixFinderAlg::findDfDz:PHI0] nent: %3i mpvPhi0: %9.6f meanPhi0  : %9.6f under: %3.0f over: %3.0f ENTRIES:",
// 	     nentriesphi, mpvphi0,  menaphi0,
// 	     _hPhi0Res->GetBinContent(0),_hPhi0Res->GetBinContent(_hPhi0Res->GetNbinsX()+1)
// 	     );
//       for (int i=0; i<_hPhi0Res->GetNbinsX(); i++) {
// 	printf(" %3.0f",_hPhi0Res->GetBinContent(i+1));
//       }
//       printf("\n");
//     }
// //-----------------------------------------------------------------------------
// // Part 2: try to perform a more accurate estimate - straight line fit
// //-----------------------------------------------------------------------------
//     float z0, phi0, dphidz, pred;

//     z0     = 0.    ;
//     phi0   = _hphi0;
//     dphidz = _hdfdz;
//     //    _sdfdz = -1;

//     if (_debug > 5) {
//       float tmpphi0=phi0+dphidz*z0;
//       printf("[CalHelixFinderAlg::findDfDz:PART2] phi0 = %9.6f dfdz = %9.6f\n", tmpphi0, dphidz);
//     }
// //--------------------------------------------------------------------------------
// // 2015-03-25 G. Pezzu changed the way the 2PI ambiguity is resolved
// //--------------------------------------------------------------------------------
//     LsqSums4 szphi;

//     weight = 1./(_sigmaPhi*_sigmaPhi);

//     float xdphi, zLast(z0), zdist;

//     if (_debug > 5) {
//       printf("[CalHelixFinderAlg::findDfDz:LOOP]  i       z        dz      phiVec     phi    szphi.dfdz    dphi    xdphi     dfdz    \n");
//     }

//     dz   = zCl - z0;
//     dphi = dz*dphidz + phi0 - phiCl;
//     while (dphi > M_PI){
//       phiCl += 2*M_PI;
//       dphi  -= 2*M_PI; // dz*dphidz + phi0 - phiCl;
//     }
//     while (dphi < -M_PI){
//       phiCl -= 2*M_PI;
//       dphi  += 2*M_PI; // = dz*dphidz + phi0 - phiCl;
//     }

//     float errCl    = 2./30.;
//     float weightCl = 1./(errCl*errCl);

//     xdphi = fabs(dphi)/errCl;
// //-----------------------------------------------------------------------------
// // 2015-04-21 Gianipez added the condition (xdphi < 2.*_maxXDPhi) for adding or not
// // the calorimeter point to the fitter. In case the particle scattered in the end of the tracker
// // the calorimeter point is dangerous.
// //-----------------------------------------------------------------------------
//     if (xdphi < 2.*_maxXDPhi){
//       szphi.addPoint(zCl, phiCl, weightCl);
//     }

//     if (_debug > 10) {
//       printf("[CalHelixFinderAlg::findDfDz:LOOP] %3i %9.3f %9.3f %9.5f %9.5f %9.6f %9.6f %9.6f %9.6f\n",
// 	     0, zCl, dz, phiCl, phiCl, szphi.dfdz(), dphi, xdphi, dphidz);
//     }

//     // 2015-07-06 Gianipez added the following line for avoiding infinite loops
//     if ( i0 < 0 ) goto NEXT_STEP;

//     for (int i=i0; i<nstations; i++) {
//       if (nhits[i] > 0) {
// 	z    = zVec[i];
// 	dz   = z-z0;
// 	pred = phi0 + dz*dphidz;
// 	phi  = phiVec[i];
// 	dphi = phi - pred;//pred - phi;

// 	while (dphi > M_PI){
// 	  phi -= 2*M_PI;//+= 2*M_PI;
// 	  dphi = phi - pred;//pred - phi;
// 	}
// 	while (dphi < -M_PI){
// 	  phi += 2*M_PI;//-= 2*M_PI;
// 	  dphi = phi - pred;//pred - phi;
// 	}

// 	xdphi = fabs(dphi)/_sigmaPhi;

// 	if (xdphi < 2.*_maxXDPhi){
// 	  szphi.addPoint(z, phi, weight);

// 	  zdist = z - zLast;

// 	  if ( (szphi.qn() >= 3.) && (zdist > 500.)){
// 	    z0     = 0.;
// 	    phi0   = szphi.phi0();
// 	    dphidz = szphi.dfdz();
// 	  }
// 	}

// 	if (_debug > 10) {
// 	  float tmpDfDz = szphi.dfdz();//, Helix._szphi.chi2DofLine());
// 	  printf("[CalHelixFinderAlg::findDfDz:LOOP] %3i %9.3f %9.3f %9.5f %9.5f %9.6f %9.6f %9.6f %9.6f\n",
// 		 i, z, dz, phiVec[i], phi, tmpDfDz, dphi, xdphi, dphidz);
// 	}
//       }
//     }

//   NEXT_STEP:;

//     if (szphi.qn() >= 3.) {
//       _hdfdz = szphi.dfdz();		// sigxy/sigxx;
//       _hphi0 = szphi.phi0();		// ymean - xmean*sigxy/sigxx;
//       //      _sdfdz = szphi.chi2DofLine();
//     }
//     else {
//       _hphi0 = phi0 + _hdfdz*z0;
//       //      _sdfdz = -1;
//     }

//     int     nActive_stations = nentries - overflows;
    
//     if (Diag_flag > 0){
//       Helix._diag.nStationPairs = nActive_stations;
//     }

//     if (_debug > 5) {
//       printf("[CalHelixFinderAlg::findDfDz] END: _hdfdz = %9.5f _hphi0 = %9.6f chi2 = %9.3f ", _hdfdz,
// 	     _hphi0, -1.);
//       printf(" FIT: szphi.dfdz() = %9.5f szphi.phi0() = %9.6f chi2 = %9.3f qn = %6.0f\n", szphi.dfdz(),
// 	     szphi.phi0(), szphi.chi2DofLine(), szphi.qn());
//     }
// //----------------------------------------------------------------------------- 
// // 2017-11-14 gianipez: in case of less than _minNSt active stations we should 
// //                      probably use the _mpDfDz
// //-----------------------------------------------------------------------------
//     if (nActive_stations < _minNSt) {
//       _hdfdz = _mpDfDz;
//       return 0;
//     }

    return 1;
  }