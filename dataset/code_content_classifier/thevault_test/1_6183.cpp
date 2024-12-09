double
SoundIdentificationProcessing::PreAccent(double z)
{
	double factor = 0.9;
	return (z)?(1 - factor * pow(z,-1)) :(0);
}