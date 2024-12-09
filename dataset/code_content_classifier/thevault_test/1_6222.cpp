void SoundProcessing::filter(double *input_Re, double *input_Im,
							 double lowFreq, double highFreq)
{
	int i = 0;
	int lowIndex  = int ((lowFreq  / _SamplesPerSec)*numSamples);
	int highIndex = int ((highFreq / _SamplesPerSec)*numSamples);

	ACE_ASSERT(highIndex < numFreqSamples);
	ACE_ASSERT(lowIndex  < highIndex);
	
	//----------------------------------------------------------------------
	//  Setting to cero the frequencies over the highindex
	//----------------------------------------------------------------------
	for ( i = highIndex; i < numFreqSamples - highIndex; i++ )
	{
		input_Re[i] = 0.0;
		input_Im[i] = 0.0;
	}
	// Original code
	/*************************************************************************
	 * nspzbZero(input+highIndex,numFreqSamples-highIndex); 				 *
	 *************************************************************************/
	
	//----------------------------------------------------------------------
	//  Setting to cero the frequencies under the lowIndex
	//  Note: is it sure this is correct???????
	//----------------------------------------------------------------------
#if 0
	if (lowIndex>0)
		for ( i = lowIndex; i < lowIndex; i++)
		{
			input_Re[i] = 0.0;
			input_Im[i] = 0.0;
		}
#endif
	//Original code
	/***************************************
	 * if (lowIndex>0)                     *
	 * nspzbZero(input+lowIndex,lowIndex); *
	 ***************************************/
}