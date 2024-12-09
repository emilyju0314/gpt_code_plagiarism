double
SoundIdentificationProcessing::HammingPonderation(const unsigned int N,
												  const unsigned int k)
{
	double hamm = 0.54 - 0.46 * cos( (2 * PI / (N -1)) * k );
	return hamm;
}