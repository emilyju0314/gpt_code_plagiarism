INT32 DistanceOfIntendedHelicopterPath( void )
{
	INT32 iLength = 0;
	if (!CanHelicopterFly())
	{
		// big number, no go
		return( 9999 );
	}

	PathSt const* pNode = GetHelicopter().pMercPath;

	// any path yet?
	if( pNode != NULL )
	{
		while( pNode -> pNext )
		{
			iLength++;
			pNode = pNode ->pNext;
		}
	}

	pNode = pTempHelicopterPath;

	// any path yet?
	if( pNode != NULL )
	{
		while( pNode -> pNext )
		{
			iLength++;
			pNode = pNode ->pNext;
		}
	}
	return( iLength );
}