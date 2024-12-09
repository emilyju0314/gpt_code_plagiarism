int GetLineNumber( char *fnFDR, int nOption, int &nHorLine, int &nVerLine, CROSS *&HCross, CROSS *&VCross )
{
	LINE *pLine, *HorLine=NULL, *VerLine=NULL;
	int  nLine;
	ReadDetectResult( fnFDR, pLine, nLine );
	switch( nOption )
	{
	case HOR_LINE:
		GetHorLine( pLine, nLine, HorLine, nHorLine );
		break;
	case VER_LINE:
		GetVerLine( pLine, nLine, VerLine, nVerLine );
		break;
	case ALL_LINE:
		GetHorLine( pLine, nLine, HorLine, nHorLine );
		GetVerLine( pLine, nLine, VerLine, nVerLine );
		// Get crossing relationship between horizontal and vertical lines
		if( nHorLine > 0 && nVerLine > 0 )
		{
			HCross = (CROSS*)malloc( sizeof(CROSS)*nHorLine );
			VCross = (CROSS*)malloc( sizeof(CROSS)*nVerLine );
			GetCrossRelation( HorLine, nHorLine, VerLine, nVerLine, HCross, VCross );
		}
		break;
	};
	if( HorLine != NULL )
		free( HorLine );
	if( VerLine != NULL )
		free( VerLine );
	free( pLine );
	return 0;
}