void MercsContractIsFinished(SOLDIERTYPE* const pSoldier)
{
	//if the soldier was removed before getting into this function, return
	if( !pSoldier->bActive )
		return;

	if( fShowContractMenu )
	{
		fShowContractMenu = FALSE;
	}

	// go to mapscreen
	MakeDialogueEventEnterMapScreen();

	if( pSoldier->ubWhatKindOfMercAmI == MERC_TYPE__MERC )
	{
		//if the players account status is invalid
		if( LaptopSaveInfo.gubPlayersMercAccountStatus == MERC_ACCOUNT_INVALID )
		{
			//Send the merc home

			InterruptTime();
			PauseGame();

			// Say quote for wishing to leave
			TacticalCharacterDialogue( pSoldier, QUOTE_NOT_GETTING_PAID );

			MakeCharacterDialogueEventContractEndingNoAskEquip(*pSoldier);

			pSoldier->ubLeaveHistoryCode = HISTORY_MERC_QUIT;
		}
	}
	else if( pSoldier->ubWhatKindOfMercAmI == MERC_TYPE__NPC )
	{
		InterruptTime();
		PauseGame();

		TacticalCharacterDialogue( pSoldier, QUOTE_AIM_SEEN_MIKE );

		MakeCharacterDialogueEventContractEndingNoAskEquip(*pSoldier);

		pSoldier->ubLeaveHistoryCode = HISTORY_MERC_QUIT;

	}
}