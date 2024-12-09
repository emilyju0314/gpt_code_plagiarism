int	GetCrossRelation( LINE *HorLine, int nHorLine, LINE *VerLine, int nVerLine, CROSS *HCross, CROSS *VCross )
{
	int i, j;
	double	nDist, D1, D2;
	int		TH = 20;
	DSCC_CPoint	StOffset, EdOffset, CrossPnt;
	// Get crossing information for horizontal lines
	StOffset.y = EdOffset.y = 0;
	for( i=0; i<nHorLine; i++ )
	{
		double	nStMin = 1e+10, nEdMin = 1e+10;
		int		nStMinIndex, nEdMinIndex;
		for( j=0; j<nVerLine; j++ )
		{
			CrossPnt	= GetCrossPoint( HorLine[i].StPnt, VerLine[j].StPnt, VerLine[j].EdPnt );
			nDist		= GetDistance( HorLine[i].StPnt, CrossPnt );
			D1			= CrossPnt.y - VerLine[j].StPnt.y;
			D2			= CrossPnt.y - VerLine[j].EdPnt.y;
			if( D1*D2 > 0 )
				nDist	+= min( fabs(D1), fabs(D2) );

			if( nDist < nStMin )
			{
				nStMin		= nDist;
				nStMinIndex = j;
				StOffset.x	= HorLine[i].StPnt.x - CrossPnt.x;
			}
			CrossPnt	= GetCrossPoint( HorLine[i].EdPnt, VerLine[j].StPnt, VerLine[j].EdPnt );
			nDist		= GetDistance( HorLine[i].EdPnt, CrossPnt );
			D1			= CrossPnt.y - VerLine[j].StPnt.y;
			D2			= CrossPnt.y - VerLine[j].EdPnt.y;
			if( D1*D2 > 0 )
				nDist	+= min( fabs(D1), fabs(D2) );

			if( nDist < nEdMin )
			{
				nEdMin		= nDist;
				nEdMinIndex = j;
				EdOffset.x	= HorLine[i].EdPnt.x - CrossPnt.x;
			}
		}

		HCross[i].nStLine	= nStMinIndex;
		if( nStMin < TH )
			HCross[i].StOffset	= DSCC_CPoint(0,0);
		else
			HCross[i].StOffset	= StOffset;

		HCross[i].nEdLine = nEdMinIndex;
		if( nEdMin < TH )
			HCross[i].EdOffset	= DSCC_CPoint(0,0);
		else
			HCross[i].EdOffset	= EdOffset;
	}

	// Get crossing information for vertical lines
	StOffset.x = EdOffset.x = 0;
	for( i=0; i<nVerLine; i++ )
	{
		double	nStMin = 1e+10, nEdMin = 1e+10;
		int		nStMinIndex, nEdMinIndex;
		for( j=0; j<nHorLine; j++ )
		{
			CrossPnt	= GetCrossPoint( VerLine[i].StPnt, HorLine[j].StPnt, HorLine[j].EdPnt );
			nDist		= GetDistance( VerLine[i].StPnt, CrossPnt );
			D1			= CrossPnt.x - HorLine[j].StPnt.x;
			D2			= CrossPnt.x - HorLine[j].EdPnt.x;
			if( D1*D2 > 0 )
				nDist	+= min( fabs(D1), fabs(D2) );

			if( nDist < nStMin )
			{
				nStMin		= nDist;
				nStMinIndex = j;
				StOffset.y	= VerLine[i].StPnt.y - CrossPnt.y;
			}
			CrossPnt	= GetCrossPoint( VerLine[i].EdPnt, HorLine[j].StPnt, HorLine[j].EdPnt );
			nDist		= GetDistance( VerLine[i].EdPnt, CrossPnt );
			D1			= CrossPnt.x - HorLine[j].StPnt.x;
			D2			= CrossPnt.x - HorLine[j].EdPnt.x;
			if( D1*D2 > 0 )
				nDist	+= min( fabs(D1), fabs(D2) );

			if( nDist < nEdMin )
			{
				nEdMin		= nDist;
				nEdMinIndex = j;
				EdOffset.y	= VerLine[i].EdPnt.y - CrossPnt.y;
			}
		}
		VCross[i].nStLine = nStMinIndex;
		if( nStMin < TH )
			VCross[i].StOffset	= DSCC_CPoint(0, 0);
		else
			VCross[i].StOffset	= StOffset;

		VCross[i].nEdLine = nEdMinIndex;
		if( nEdMin < TH )
			VCross[i].EdOffset	= DSCC_CPoint(0, 0);
		else
			VCross[i].EdOffset	= EdOffset;
	}
	return 0;
}