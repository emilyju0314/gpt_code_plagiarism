int 
SoundProcessing::ConjComplexMultiplication(double * a, double * b,
										   double * c, double * d,
										   double * ans_Re , double * ans_Im)
{
	for	( int i = 0; i < numSamples; i++) 
	{
		*(ans_Re+i) = ((*a) * (*c) + (*b) * (*d))/numSamples;
		*(ans_Im+i) = ((*b) * (*c) - (*a) * (*d))/numSamples;
		a++; b++; c++; d++;
	}

	return 0;
}