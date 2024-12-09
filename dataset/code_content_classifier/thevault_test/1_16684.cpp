int GetEndPoint( LINE &Line, COLRUNLENGTH *ColRun, int nRun )
{
	int nLeftCount=0;
	int nRightCount=0; 
	int	nLineRun = 0;

	//Test if the line is a virtual line
	int i, j;
	for( i=0; i<nRun; i++ )
	{
		if( ColRun[i].bUsed == FALSE )	continue;
		nLineRun ++;
	}
	if( nLineRun <= MIN_PIXEL )
		return -1;

	//Get MMSE approximate esimate of line parameters
	double a, b;
	GetLineParam( ColRun, nRun, a, b );
	double nSkewVar = fabs(atan(b) - atan2( (double)(Line.EdPnt.y-Line.StPnt.y), (double)(Line.EdPnt.x - Line.StPnt.x) ) ) * 180/PI;
	if( nSkewVar > 2.5 )	//Skew variance is too large
		return -1;
	//Search left end point
	for( i=0; i<nRun; i++ )
	{
		if( ColRun[i].bUsed == FALSE )	continue;
		nLeftCount++;
		if( nLeftCount >= 3 )
		{
			for(j=i; j>=0; j--)
			{
				if( ColRun[i].bUsed == FALSE )
					continue;
				if( abs(ColRun[j].x - ColRun[i].x)>6 )
					break;
			}
			j = max( 0, j );
			Line.StPnt.x = ColRun[j].x;
			Line.StPnt.y = (int)(a + b*ColRun[j].x );
			break;
		}
	}

//Search right end point
	for( i=nRun-1; i>=0; i-- )
	{
		if( ColRun[i].bUsed == FALSE )	continue;
		nRightCount++;
		if( nRightCount >= 3 )
		{
			for( j=i; j<nRun; j++ )
			{
				if( ColRun[j].bUsed == FALSE )	
					continue;
				if( abs(ColRun[j].x - ColRun[i].x ) > 6 )
					break;
			}
			j = min( nRun-1, j);
			Line.EdPnt.x = ColRun[j].x;
			Line.EdPnt.y = (int)(a + b*ColRun[j].x );
			break;
		}
	}
	return 0;
}