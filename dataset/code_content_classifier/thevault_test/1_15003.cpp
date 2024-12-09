void HandleLoyaltyImplicationsOfMercRetreat( INT8 bRetreatCode, INT16 sSectorX, INT16 sSectorY, INT16 sSectorZ )
{
	if( CountAllMilitiaInSector( sSectorX, sSectorY ) )
	{ //Big morale penalty!
		HandleGlobalLoyaltyEvent( GLOBAL_LOYALTY_ABANDON_MILITIA, sSectorX, sSectorY, (INT8)sSectorZ );
	}

	//Standard retreat penalty
	if ( bRetreatCode == RETREAT_TACTICAL_TRAVERSAL )
	{
		// if not worse than 2:1 odds, then penalize morale
		if ( gTacticalStatus.fEnemyInSector && ( PlayerStrength() * 2 >= EnemyStrength() ) )
		{
			HandleMoraleEvent( NULL, MORALE_RAN_AWAY, sSectorX, sSectorY, (INT8)sSectorZ );
		}
	}
	else
	{
		HandleMoraleEvent( NULL, MORALE_RAN_AWAY, sSectorX, sSectorY, (INT8)sSectorZ );
	}
}