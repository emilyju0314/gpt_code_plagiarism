double 
SoundIdentificationProcessing::Triangularfilter(
	const double *input_Re, 
	int k
	) {
	int i                   = 0;
	double filter_output    = 0.0;
	double energy           = 0.0;
	double lowFreq          = 0.0;
	double centerFreq       = 0.0;
	double upperFreq        = 0.0;
	double triangleHeight   = 0.0;
	double last_linear_freq = 0.0;
	double fftFreq          = 0.0;

	//----------------------------------------------------------------------
	// Calculate the lowFreq, centerFreq and upperFreq of the filter 
	//----------------------------------------------------------------------
	k++;
	if (k <= linearFilters)
	{
		lowFreq    = lowestFrequency + (k - 1) * linearSpacing;
		centerFreq = lowestFrequency +  k      * linearSpacing;
		upperFreq  = lowestFrequency + (k + 1) * linearSpacing;
	}
	else // In the case we are in the logarithmic filter distribution
	{
		last_linear_freq = lowestFrequency + (linearFilters * linearSpacing);
		lowFreq          = last_linear_freq * pow(logSpacing, (k-linearFilters+1));
		centerFreq       = last_linear_freq * pow(logSpacing, (k-linearFilters+2));
		upperFreq        = last_linear_freq * pow(logSpacing, (k-linearFilters+3));
	}

	//Calculate the height of the triangle filter
	triangleHeight = (double)2.0 / (double)(upperFreq-lowFreq);

	//----------------------------------------------------------------------
	//  Apply the filter taking care to apply the correct triangle height
	//  Acumulate the energy response of the filter
	//----------------------------------------------------------------------
	for ( i = 0; i < numSamples; i++)
	{
		int fftsize = numSamples;
		fftFreq = (((double)i/(double)fftsize) * (double)_SamplesPerSec);

		if ( fftFreq > lowFreq && fftFreq <= centerFreq)
			filter_output = input_Re[i] * triangleHeight * ((double)(fftFreq - lowFreq)/(double)(centerFreq - lowFreq));
		else if ( fftFreq > centerFreq && fftFreq < upperFreq)
			filter_output = input_Re[i] * triangleHeight * ((double)(upperFreq - fftFreq)/(double)(upperFreq - centerFreq));
		else
			filter_output = 0.0;

		energy += filter_output;
	}

	return log10f(energy);
}