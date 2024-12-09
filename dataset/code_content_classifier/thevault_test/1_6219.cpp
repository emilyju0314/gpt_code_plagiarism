double
SoundProcessing::scalarProduct(double * channel1, double *channel2, int sizeChannel)
{
	double scalar = 0;
	for (int i = 0; i < sizeChannel; i++)
	{
		scalar += double (channel1[i]) * channel2[i];
	}
	return scalar;
}