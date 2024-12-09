int RegualizeLineGapEstimate( double *Prob, int nProb )
{
	int i;
	// Making the distribution symmetric
	double	nMin = 1e+100;
	for( i=1; i<=nProb/2; i++ )
	{
		double	nAver = Prob[i] + Prob[nProb-i];
		Prob[i] = Prob[nProb-i] = nAver;
		if( nAver > 0 )
			nMin = min( nMin, nAver );
	}

	// Replacing zeros with a small value
	for( i=1; i<=nProb/2; i++ )
		if( Prob[i] != 0 )
			break;
//	int nBound = i-max(3, 0.1*(nProb/2-i));	//Extend the boundary a little bit
	int nBound = i-0.1*(nProb/2-i);			//Extend the boundary a little bit
	nBound = max( nBound, 0 );
	for( i=nBound; i<=nProb-nBound; i++ )
		Prob[i] = max( Prob[i], nMin );
	return nProb/2-nBound;
}