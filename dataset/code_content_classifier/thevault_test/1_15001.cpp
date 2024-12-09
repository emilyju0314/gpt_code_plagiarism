void CheckIfEntireTownHasBeenLiberated( INT8 bTownId, INT16 sSectorX, INT16 sSectorY )
{
	// the whole town is under our control, check if we never libed this town before
	if ( !gTownLoyalty[ bTownId ].fLiberatedAlready && IsTownUnderCompleteControlByPlayer ( bTownId ) )
	{
		if ( MilitiaTrainingAllowedInSector( sSectorX, sSectorY, 0 ) )
		{
			// give a loyalty bonus
			HandleGlobalLoyaltyEvent( GLOBAL_LOYALTY_LIBERATE_WHOLE_TOWN, sSectorX, sSectorY, 0 );

			// set fact is has been lib'ed and set history event
			AddHistoryToPlayersLog( HISTORY_LIBERATED_TOWN, bTownId, GetWorldTotalMin(), sSectorX, sSectorY );

			HandleMeanWhileEventPostingForTownLiberation( bTownId );
		}

		// even taking over non-trainable "towns" like Orta/Tixa for the first time should count as "player activity"
		if ( gGameOptions.ubDifficultyLevel >= DIF_LEVEL_HARD )
		{
			UpdateLastDayOfPlayerActivity( ( UINT16 ) ( GetWorldDay() + 4 ) );
		}
		else
		{
			UpdateLastDayOfPlayerActivity( ( UINT16 ) ( GetWorldDay() + 2 ) );
		}

		// set flag even for towns where you can't train militia, useful for knowing Orta/Tixa were previously controlled
		gTownLoyalty[ bTownId ].fLiberatedAlready = TRUE;
	}
}