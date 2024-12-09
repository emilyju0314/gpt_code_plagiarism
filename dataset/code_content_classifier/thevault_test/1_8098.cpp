bool RobustHelixFit::initFZ_from_dzFrequency(RobustHelixFinderData& HelixData, int InitHiPhi){
    bool retval(false);
    RobustHelix& rhel         = HelixData._hseed._helix;

    rhel._lambda = 1.0e12; //infinite slope for now
    rhel._fz0    = 0.0;
    static TrkFitFlag circleOK(TrkFitFlag::circleOK);
    static TrkFitFlag helixOK(TrkFitFlag::helixOK);

    // make initial estimate of dfdz using 'nearby' pairs.  This insures they are on the same loop
    // need to define an array of a given length 
    std::vector<int> hist(_initFZFrequencyArraySize);
    std::vector<int> hist_sum(_initFZFrequencyArraySize);
    float            bin_size(16.);//mm
    float            start_dz(0);
    float            dzdphisign(0);

    if (rhel.helicity()._value == Helicity::neghel) {
      dzdphisign = -1.;
    }
    else if (rhel.helicity()._value == Helicity::poshel) {
      dzdphisign = 1.;
    }

    if (!fillArrayDz(HelixData, hist, bin_size, start_dz)){
      return false;
    }
      
    //create the histogram of the sum of N-consectutive bins
    for (int i = 0; i<_initFZFrequencyArraySize - _initFZFrequencyBinsToIntegrate; i++){ 
      int sum(0);
      for (int j = 0; j< _initFZFrequencyBinsToIntegrate; j++){
	sum += hist[i+j];
      }
      hist_sum[i] = sum;
    }

    if (InitHiPhi > 0) {
      ComboHit *hit(0);
      for (unsigned i=0; i<HelixData._chHitsToProcess.size(); ++i){ 
	hit = &HelixData._chHitsToProcess[i];
	if (!use(*hit))             continue;
	initPhi(*hit,rhel); 
      }
    }
    
    //-----------------------------------------------------------------------------
    // the 'histogram' is filled, find a peak
    //-----------------------------------------------------------------------------
    if (_debug > 0) {
      printf("[RobustHelixFinder::initFZ:PEAK_SEARCH]   dzdphisign   counter  ix   hist[ix]   sw\n");
    }
    
    int                peaks_found(0);
    std::vector<float> swmax(_initFZFrequencyNMaxPeaks), xmp(_initFZFrequencyNMaxPeaks), sigma(_initFZFrequencyNMaxPeaks);
    std::vector<int>   indexPeak;(_initFZFrequencyNMaxPeaks);
    int                first_peak(-1);
    float              minNCounts(10.);

    findHistPeaks(hist_sum, bin_size, start_dz, xmp, sigma, swmax, indexPeak, first_peak, peaks_found);
    
    //now, evaluate the weighted average of the lambda values found from the peak search
    float     total_wg(0), weight_lambda(0);
    for (int i=1; i<_initFZFrequencyNMaxPeaks; ++i){
      if (swmax[i]>minNCounts){
	if ( (xmp[i] - _initFZFrequencyNSigma*sigma[i]>0) && (xmp[i-1] - _initFZFrequencyNSigma*sigma[i-1]>0)){
	  double   wg = sqrt(swmax[i]*swmax[i-1]);
	  weight_lambda += wg*(xmp[i] - xmp[i-1])/6.28;//(lambda[i]*swmax[i]);
	  total_wg   += wg;
	}
      }
    }
    weight_lambda /= total_wg;

    if (peaks_found == 1) weight_lambda = xmp[first_peak]/6.28;

    float lambda_final = weight_lambda*dzdphisign;

    if(!goodLambda( rhel.helicity(),lambda_final) ) return retval;
    rhel._lambda = lambda_final;

    if (_diag){
      HelixData._diag.lambda_0 = rhel._lambda;
    }

    float  fz0(0);    
    if(extractFZ0(HelixData, fz0))
      {
	rhel._fz0 = deltaPhi(0.0,fz0);
	for (auto &hitP1: HelixData._chHitsToProcess){
	  resolvePhi(hitP1,rhel);
	}
	retval = true;
      }

    return retval;
  }