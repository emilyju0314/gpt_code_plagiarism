void UpdateSummaryInfo( SUMMARYFILE *pSummary )
{
	if( pSummary->MapInfo.ubMapVersion == MINOR_MAP_VERSION )
		return;
	if( pSummary->MapInfo.ubMapVersion < 9 )
	{
		//See bug 10
		pSummary->ubCivSchedules = 0;
	}
	if( pSummary->MapInfo.ubMapVersion < 12 )
	{
		pSummary->MapInfo.sCenterGridNo = -1;
	}
	if( pSummary->MapInfo.ubMapVersion < 16 )
	{
		pSummary->MapInfo.sIsolatedGridNo = -1;
	}
}