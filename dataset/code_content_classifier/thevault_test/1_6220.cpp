double
SoundProcessing::correlation(double *channel1, double *channel2, int sizeChannel)
{
	double llScalar = scalarProduct(channel1, channel1, sizeChannel);
	double lrScalar = scalarProduct(channel1, channel2, sizeChannel);
	double rrScalar = scalarProduct(channel2, channel2, sizeChannel);

	return lrScalar/ (sqrt(llScalar * rrScalar));
}