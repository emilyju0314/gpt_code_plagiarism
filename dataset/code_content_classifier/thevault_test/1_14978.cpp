INT16 RandomGridNo()
{
	INT32 iMapXPos, iMapYPos, iMapIndex;
	do
	{
		iMapXPos = Random( WORLD_COLS );
		iMapYPos = Random( WORLD_ROWS );
		iMapIndex = iMapYPos * WORLD_COLS + iMapXPos;
	} while( !GridNoOnVisibleWorldTile( (INT16)iMapIndex ) );
	return (INT16)iMapIndex;
}