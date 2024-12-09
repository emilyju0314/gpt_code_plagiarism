int GetLineParam( COLRUNLENGTH *ColRun, int nRun, double &a, double &b )
{
	double	SumX, SumY, SumXX, SumXY;
	int		N;
//Get MMSE approximate of a line
	N = 0;
	SumX = SumY = SumXX = SumXY = 0;
	int i = 0;
	for(; i<nRun; i++ )
	{
		if( ColRun[i].bUsed == FALSE )	continue;
		SumX += ColRun[i].x;
		SumY += (ColRun[i].ys+ColRun[i].ye)*0.5;
		N++;
	}
	if( N<=0 )	return 0;

	double	ax = SumX/N;
	double  ay = SumY/N;

	for( i=0; i<nRun; i++ )
	{
		if( ColRun[i].bUsed == FALSE )	continue;
		SumXX += (ColRun[i].x - ax)*(ColRun[i].x - ax);
		SumXY += (ColRun[i].x - ax)*( 0.5*(ColRun[i].ys + ColRun[i].ye ) - ay);
	}
	b = SumXY / SumXX;
	a = ay - b*ax;
	return 0;
}