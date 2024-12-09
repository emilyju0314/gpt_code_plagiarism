double 
SoundProcessing::squareMean(double * channel_Re, double * channel_Im, double lowFreq, double highFreq)
{
	double energy = 0.0;

	int lowIndex  = int ((lowFreq/_SamplesPerSec)*numSamples);
	int highIndex = int ((highFreq/_SamplesPerSec)*numSamples);

	for(int i= lowIndex; i < highIndex; i++)
		energy = energy + 2*channel_Re[i];

	return energy;
}