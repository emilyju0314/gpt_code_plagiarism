int 
SoundProcessing::ComputeCrossCorrelation(double * left_Re, double * left_Im,
										 double * right_Re, double * right_Im)
{
	int i = 0;
	int dim[1] = {numSamples};

	//----------------------------------------------------------------------
	//  Filter the signals
	//----------------------------------------------------------------------
	filter(left_Re  , left_Im  , 0 , FREQ_T);
	filter(right_Re , right_Im , 0 , FREQ_T);

	//----------------------------------------------------------------------
	//  Compute the complex conjugate multiplications
	//----------------------------------------------------------------------
	ConjComplexMultiplication(left_Re, left_Im,
							  right_Re, right_Im,
							  crosscorrelation_Re,
							  crosscorrelation_Im);
	ConjComplexMultiplication(left_Re, left_Im,
							  left_Re, left_Im,
							  leftcorrelation_Re,
							  leftcorrelation_Im);
	ConjComplexMultiplication(left_Re, left_Im,
							  right_Re, right_Im,
							  rightcorrelation_Re,
							  rightcorrelation_Im);
	
	//----------------------------------------------------------------------
	//  Appling SCOT filter is selected by the user. ( option in the 
	//  sound.ini file) 
	//----------------------------------------------------------------------
	if ( _SCOTfiltering )
	{
		for( int i=0; i<numSamples; i++)
		{
			if ((rightcorrelation_Re[i] > 0.6) && (leftcorrelation_Re[i] > 0.6))
				SCOToperator_Re[i] = 1/sqrt(rightcorrelation_Re[i] * leftcorrelation_Re[i]);
			else
				SCOToperator_Re[i] = 0.0;

			SCOToperator_Im[i] = 0.0;
		}

		ComplexMultiplication(crosscorrelation_Re, 
							  crosscorrelation_Im,
							  SCOToperator_Re, 
							  SCOToperator_Im);
	}
	
	//----------------------------------------------------------------------
	//  Calculate the inverse Fast Fourier Transform
	//  At the end the crosscorrelation_Re vector should contain the crosscorre-
	//  lation data
	//----------------------------------------------------------------------
	fft->Fft(1, dim, crosscorrelation_Re, crosscorrelation_Im, -1, -1);

	//----------------------------------------------------------------------
	//  Rearange the crosscorrelation_Re to have a coheren visualization of
	//  the crosscorrelation. Assign the corrVectFreq to the correct position
	//  inside crosscorrelation_Re
	//----------------------------------------------------------------------
	for (i = 0; i < numSamples; i++)
		crosscorrelation_Re[i + numSamples] = crosscorrelation_Re[i];

	corrVectFreq = &crosscorrelation_Re[numSamples - shift - bias];
	
	double tempCorr = 0.0;
	int ind = shift;
	
	//----------------------------------------------------------------------
	//  Calculate the crosscorrelation maximum 
	//----------------------------------------------------------------------
	double * ptempcross = corrVectFreq;

	for ( i = 0; i < windowMax; i++)
		if ( ptempcross[i] > tempCorr)
		{
			tempCorr = ptempcross[i];
			ind = i;
		}

	corrMax   = tempCorr;
	corrShift = ind;

	//----------------------------------------------------------------------
	//  Forcing the vector to be between +/- 1
	//----------------------------------------------------------------------
	if ( corrMax > 0)
		for ( i = 0; i < windowMax; i++)
			corrVectFreq[i] *= 1/corrMax;

	return 0;
}