int GetEndPoint( LINE &Line, ROWRUNLENGTH *RowRun, int nRun )
{
	int nLeftCount=0;
	int nRightCount=0; 
	int	nLineRun = 0;

	//Test if the line is a virtual line
	int i, j;
	for( i=0; i<nRun; i++ )
	{
		if( RowRun[i].bUsed == FALSE )	continue;
		nLineRun ++;
	}
	if( nLineRun <= MIN_PIXEL )
		return -1;

	//Get MMSE approximate esimate of line parameters
	double a, b;
	GetLineParam( RowRun, nRun, a, b );
	double nAngle = atan2( (double)(Line.EdPnt.x-Line.StPnt.x), (double)(Line.EdPnt.y - Line.StPnt.y) );
	double nSkewVar = fabs(atan(b) - nAngle ) * 180/PI;
	int  nLen = fabs((float)(Line.EdPnt.y - Line.StPnt.y));
	if( nLen > 300 && nSkewVar > 2.5 )//Skew variance is too large
		return -1;
	//Search left end point
	for( i=0; i<nRun; i++ )
	{
		if( RowRun[i].bUsed == FALSE )	continue;
		nLeftCount++;
		if( nLeftCount >= 3 )
		{
			for(j=i; j>=0; j--)
			{
				if( RowRun[i].bUsed == FALSE )
					continue;
				if( abs(RowRun[j].y - RowRun[i].y)>6 )
					break;
			}
			j = max( 0, j );
			Line.StPnt.y = RowRun[j].y;
			Line.StPnt.x = (int)(a + b*RowRun[j].y );
			break;
		}
	}

//Search right end point
	for( i=nRun-1; i>=0; i-- )
	{
		if( RowRun[i].bUsed == FALSE )	continue;
		nRightCount++;
		if( nRightCount >= 3 )
		{
			for( j=i; j<nRun; j++ )
			{
				if( RowRun[j].bUsed == FALSE )	
					continue;
				if( abs(RowRun[j].y - RowRun[i].y ) > 6 )
					break;
			}
			j = min( nRun-1, j);
			Line.EdPnt.y = RowRun[j].y;
			Line.EdPnt.x = (int)(a + b*RowRun[j].y );
			break;
		}
	}
	return 0;
}