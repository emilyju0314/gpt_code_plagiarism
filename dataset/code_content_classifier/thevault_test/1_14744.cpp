void RemoveProgressBar( UINT8 ubID )
{
	Assert( ubID < MAX_PROGRESSBARS );
	if( pBar[ubID] )
	{
		delete pBar[ubID];
		pBar[ubID] = NULL;
		return;
	}
}