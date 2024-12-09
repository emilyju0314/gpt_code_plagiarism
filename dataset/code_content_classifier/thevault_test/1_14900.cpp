void ResetMovementForEnemyGroupsInLocation( UINT8 ubSectorX, UINT8 ubSectorY )
{
	INT16 sSectorX, sSectorY, sSectorZ;

	GetCurrentBattleSectorXYZ( &sSectorX, &sSectorY, &sSectorZ );
	FOR_EACH_GROUP_SAFE(pGroup)
	{
		if( !pGroup->fPlayer )
		{
			if( pGroup->ubSectorX == sSectorX && pGroup->ubSectorY == sSectorY )
			{
				ResetMovementForEnemyGroup( pGroup );
			}
		}
	}
}