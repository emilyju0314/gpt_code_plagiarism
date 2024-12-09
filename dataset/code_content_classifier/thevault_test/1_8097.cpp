void RobustHelixFit::findHistPeaks(std::vector<int>&hist_sum, int binWidth,
				     float &start_dz,
				     std::vector<float> &xmp, std::vector<float> &sigma, std::vector<float> &swmax, std::vector<int> &indexPeak,int &first_peak, int & peaks_found){
    

    float  shift_dz(_initFZFrequencyBinsToIntegrate*binWidth/2.);
    float  sw(0);
    int    bin_index(0);

    for (int ipeak=0; ipeak<_initFZFrequencyNMaxPeaks; ++ipeak){
      //      if (ipeak>0) bin_index = (xmp[ipeak-1] + 0.4*lambda[ipeak-1]*6.28 - start_dz)/bin_size;//shifting the starting pos 1/2 pitch from the previous peak
      if (ipeak>0) bin_index = (xmp[ipeak-1] + _initFZFrequencyNSigma*sigma[ipeak-1])/binWidth;//shifting the starting pos 1/2 pitch from the previous peak
      
      if (bin_index >= _initFZFrequencyArraySize-_initFZFrequencyBinsToIntegrate)       break;

      for (int ix= bin_index; ix<_initFZFrequencyArraySize-_initFZFrequencyBinsToIntegrate; ix++) {
    	sw  = 0;
    	for (int l=0; l<_initFZFrequencyBinsToIntegrate; ++l){
    	  sw += hist_sum[ix+l];//hdz->GetBinContent(ix+l+1);
    	}
    	if (sw > swmax[ipeak] + _initFZFrequencyTolerance*swmax[ipeak]) { 
    	  xmp[ipeak] = 0;
    	  //now, calculate the weighted average
    	  for (int l=0; l<_initFZFrequencyBinsToIntegrate; ++l){
    	    xmp[ipeak] = xmp[ipeak] + binWidth*(ix + l + 0.5)*hist_sum[ix+l]; //*hdz->GetBinContent(ix+l+1);
    	  }
    	  xmp[ipeak]  /= sw;
    	  xmp[ipeak]  += start_dz;
    	  xmp[ipeak]  += shift_dz;
    	  indexPeak[ipeak] = ix;
    	  // if (ipeak ==0 )
    	  //   lambda[ipeak] = xmp[ipeak]/(6.28*(peaks_found+1));//ipeak!=0 ? xmp[ipeak]/(6.28*(ipeak)) : xmp[ipeak]/(6.28);
    	  // else {
    	  //   lambda[ipeak] = (xmp[ipeak] - xmp[ipeak-1])/6.28;
    	  // }
    	  swmax[ipeak] = sw;
    	}
      }//end loop pver the bins of the array 'hist'
      
      if (swmax[ipeak] <= 0)       break;
      float numerator_sum(0);
    
      //calculating the standard deviation of the peak
      for (int l=0; l<_initFZFrequencyBinsToIntegrate; ++l){
	sw             = hist_sum[indexPeak[ipeak]+l]; //hdz->GetBinContent(indexPeak[ipeak]+l+1);
	float        x = (indexPeak[ipeak] + l + .5)*binWidth +  start_dz;  //hdz->GetBinCenter(indexPeak[ipeak] + l+1);
	numerator_sum += sw*(x - xmp[ipeak])*(x - xmp[ipeak]);
      }
      sigma[ipeak] = sqrt((numerator_sum)/swmax[ipeak]);
      
      //checking if peak postion is far enogh away from dz=0
      if (xmp[ipeak]-_initFZFrequencyNSigma*sigma[ipeak]>0) {
	if (peaks_found == 0) first_peak = ipeak;
	peaks_found = peaks_found +1;
      }

    }//end the loop over npeaks

    
  }