static void PrepareForPreBattleInterface(GROUP* pPlayerDialogGroup, GROUP* pInitiatingBattleGroup)
{
	// ATE; Changed alogrithm here...
	// We first loop through the group and save ubID's ov valid guys to talk....
	// ( Can't if sleeping, unconscious, and EPC, etc....
	UINT8 ubNumMercs = 0;

	if( fDisableMapInterfaceDueToBattle )
	{
		SLOGA("fDisableMapInterfaceDueToBattle is set before attempting to bring up PBI.\
			Please send PRIOR save if possible and details on anything that just happened before this battle." );
		return;
	}

	// Pipe up with quote...
	AssertMsg( pPlayerDialogGroup, "Didn't get a player dialog group for prebattle interface." );

	AssertMsg(pPlayerDialogGroup->pPlayerList, String( "Player group %d doesn't have *any* players in it!  (Finding dialog group)", pPlayerDialogGroup->ubGroupID));

	SOLDIERTYPE* mercs_in_group[20];
	CFOR_EACH_PLAYER_IN_GROUP(pPlayer, pPlayerDialogGroup)
	{
		SOLDIERTYPE* const pSoldier = pPlayer->pSoldier;

		if (pSoldier->bLife >= OKLIFE && !IsMechanical(*pSoldier) && !AM_AN_EPC(pSoldier))
		{
			mercs_in_group[ubNumMercs++] = pSoldier;
		}
	}

	//Set music
	SetMusicMode( MUSIC_TACTICAL_ENEMYPRESENT );

	if( (gfTacticalTraversal && pInitiatingBattleGroup == gpTacticalTraversalGroup) ||
		(pInitiatingBattleGroup && !pInitiatingBattleGroup->fPlayer &&
		pInitiatingBattleGroup->ubSectorX == gWorldSectorX &&
		pInitiatingBattleGroup->ubSectorY == gWorldSectorY && !gbWorldSectorZ) )
	{	// At least say quote....
		if ( ubNumMercs > 0 )
		{
			if( pPlayerDialogGroup->uiFlags & GROUPFLAG_JUST_RETREATED_FROM_BATTLE )
			{
				gfCantRetreatInPBI = TRUE;
			}

			SOLDIERTYPE* const chosen = mercs_in_group[Random(ubNumMercs)];
			gpTacticalTraversalChosenSoldier = chosen;

			if( !gfTacticalTraversal )
			{
				HandleImportantPBIQuote(*chosen, pInitiatingBattleGroup);
			}

			InterruptTime();
			PauseGame();
			LockPauseState(LOCK_PAUSE_PREBATTLE_CURRENT_SQUAD);

			if( !gfTacticalTraversal )
				fDisableMapInterfaceDueToBattle = TRUE;
		}
		return;
	}


	// Randomly pick a valid merc from the list we have created!
	if ( ubNumMercs > 0 )
	{
		if( pPlayerDialogGroup->uiFlags & GROUPFLAG_JUST_RETREATED_FROM_BATTLE )
		{
			gfCantRetreatInPBI = TRUE;
		}

		SOLDIERTYPE* const chosen = mercs_in_group[Random(ubNumMercs)];
		HandleImportantPBIQuote(*chosen, pInitiatingBattleGroup);
		InterruptTime();
		PauseGame();
		LockPauseState(LOCK_PAUSE_PREBATTLE);

		// disable exit from mapscreen and what not until face done talking
		fDisableMapInterfaceDueToBattle = TRUE;
	}
	else
	{
		// ATE: What if we have unconscious guys, etc....
		// We MUST start combat, but donot play quote...
		InitPreBattleInterface(pInitiatingBattleGroup, true);
	}
}