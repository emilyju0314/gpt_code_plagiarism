void CWretch::AlertSound( void )
{
	CBaseEntity *pPlayer = AI_GetSinglePlayer();

	if( pPlayer )
	{
		// Measure how far the player is, and play the appropriate type of alert sound. 
		// Doesn't matter if I'm getting mad at a different character, the player is the
		// one that hears the sound.
		float flDist;

		flDist = ( GetAbsOrigin() - pPlayer->GetAbsOrigin() ).Length();

		if( flDist > 512 )
		{
			EmitSound( "NPC_Wretch.AlertFar" );
		}
		else
		{
			EmitSound( "NPC_Wretch.AlertNear" );
		}
	}

}