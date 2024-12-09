static BOOLEAN DoesSkyriderNoticeEnemiesInSector(UINT8 ubNumEnemies)
{
	UINT8 ubChance;

	// is the pilot and heli around?
	if (!CanHelicopterFly()) return FALSE;

	// if there aren't any, he obviously won't see them
	if( ubNumEnemies == 0 )
	{
		return( FALSE );
	}

	// figure out what the chance is of seeing them
	// make this relatively accurate most of the time, to encourage helicopter scouting by making it useful
	ubChance = 60 + ubNumEnemies;
	if( PreRandom( 100 ) < ubChance )
	{
		return( TRUE );
	}
	return( FALSE );
}