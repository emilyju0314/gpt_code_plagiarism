BOOLEAN AddWaypointIDToPGroup( GROUP *pGroup, UINT8 ubSectorID )
{
	UINT8 ubSectorX, ubSectorY;
	ubSectorX = SECTORX( ubSectorID );
	ubSectorY = SECTORY( ubSectorID );
	return AddWaypointToPGroup( pGroup, ubSectorX, ubSectorY );
}