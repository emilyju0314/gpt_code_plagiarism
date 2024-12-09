int 
SoundProcessing::ComplexMultiplication(double * a, double * b, double * c, double * d)
{
	double temp_a;
	
	for	(int i = 0; i < numSamples; i++) 
	{
		temp_a = (*a);
		*(a)   = ((*a) * (*c) + (*b)     * (*d))/numSamples;
		*(b)   = ((*b) * (*c) + (temp_a) * (*d))/numSamples;
		a++; b++; c++; d++;
	}

	return 0;
}