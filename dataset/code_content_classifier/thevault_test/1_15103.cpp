BOOLEAN SaveSoldiersToMap( HWFILE fp )
{
	UINT32 i;
	SOLDIERINITNODE *curr;

	if( !fp )
		return FALSE;

	if (gMapInformation.ubNumIndividuals > MAX_NUM_SOLDIERS)
		return FALSE;

	//If we are perhaps in the alternate version of the editor, we don't want bad things to
	//happen.  This is probably the only place I know where the user gets punished now.  If the
	//person was in the alternate editor mode, then decided to save the game, the current mercs may
	//not be there.  This would be bad.  What we do is override any merc editing done while in this
	//mode, and kill them all, while replacing them with the proper ones.  Not only that, the alternate
	//editing mode is turned off, and if intentions are to play the game, the user will be facing many
	//enemies!
	if (!gfOriginalList) ResetAllMercPositions();

	curr = gSoldierInitHead;
	for( i=0; i < gMapInformation.ubNumIndividuals; i++ )
	{
		if( !curr )
			return FALSE;
		curr->ubNodeID = (UINT8)i;
		InjectBasicSoldierCreateStructIntoFile(fp, *curr->pBasicPlacement);

		if( curr->pBasicPlacement->fDetailedPlacement )
		{
			if( !curr->pDetailedPlacement )
				return FALSE;
			InjectSoldierCreateIntoFile(fp, curr->pDetailedPlacement);
		}
		curr = curr->next;
	}
	return TRUE;
}