int
SoundProcessing::ComputeLevels()
{
	//----------------------------------------------------------------------
	//  The left and right correlation spectrums have been already calculated 
	//  in the CrossCorrelation computation
	//----------------------------------------------------------------------
	squareMiddleValLeft  = squareMean(leftcorrelation_Re,
									  leftcorrelation_Im,
									  ILD_LOW_FREQ,
									  FREQ_T);
	squareMiddleValRight = squareMean(rightcorrelation_Re,
									  rightcorrelation_Im,
									  ILD_LOW_FREQ,
									  FREQ_T);

	return 0;
}