int GetLineParam( ROWRUNLENGTH *RowRun, int nRun, double &a, double &b )
{
	double	SumX, SumY, SumXY, SumYY;
	int		N;
//Get MMSE approximate of a line
	N = 0;
	SumX = SumY = SumYY = SumXY = 0;
	int i = 0;
	for(; i<nRun; i++ )
	{
		if( RowRun[i].bUsed == FALSE )	continue;
		SumX += (RowRun[i].xs+RowRun[i].xe)*0.5;
		SumY += RowRun[i].y;
		N++;
	}
	if( N<=0 )	return 0;

	double	ax = SumX/N;
	double  ay = SumY/N;

	for( i=0; i<nRun; i++ )
	{
		if( RowRun[i].bUsed == FALSE )	continue;
		SumYY += (RowRun[i].y - ay)*(RowRun[i].y - ay);
		SumXY += (RowRun[i].y - ay)*( 0.5*(RowRun[i].xs + RowRun[i].xe ) - ax);
	}
	b = SumXY / SumYY;
	a = ax - b*ay;
	return 0;
}