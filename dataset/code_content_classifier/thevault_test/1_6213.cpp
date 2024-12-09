int
SoundProcessing::CrossCorrelation(double *lChannel, double *rChannel)
{
	int middleValLeft = 0;	//mean(lChannel, shift, timeMax);
	int middleValRight = 0; //mean(rChannel, shift, timeMax);

	double tempCorr = 0;
	int ind = shift; 
	
	for (int i=(shift+bias); i<(timeMax+bias); i++)
	{
		middleSampleLeft[i-(shift+bias)]=lChannel[i]; 
	}

	for (int z=0; z<windowMax; z++)
	{
		for (int i=windowMax-z; i<(windowMax-z+windowSize); i++)
		{
			middleSampleRight[i-windowMax+z]=rChannel[i]-middleValRight;
		}

		corrVect[z]=correlation(middleSampleLeft, middleSampleRight, windowSize);
		if (corrVect[z] > tempCorr)
		{
			tempCorr=corrVect[z];
			ind=z;
		}
	}

    corrMax   = tempCorr; // correlation peak
    corrShift = ind;      // shift between the two waves (itd)
	
	return 1;
}