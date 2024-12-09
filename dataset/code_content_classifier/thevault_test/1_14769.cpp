static BOOLEAN InitVideoFaceTalking(UINT8 ubMercID, UINT16 usQuoteNum)
{
	//Starts the merc talking
	CharacterDialogue(ubMercID, usQuoteNum, giMercFaceIndex, DIALOGUE_CONTACTPAGE_UI, FALSE);

	//Enables it so if a player clicks, he will shutup the merc
	gSelectedShutUpMercRegion.Enable();

	gfIsShutUpMouseRegionActive = TRUE;
	gfMercIsTalking = TRUE;
	guiTimeThatMercStartedTalking	= GetJA2Clock();
	return(TRUE);
}