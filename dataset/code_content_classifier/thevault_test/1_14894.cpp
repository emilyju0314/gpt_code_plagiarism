static void SavePlayerGroupList(HWFILE const f, GROUP const* const g)
{
	// Save the number of nodes in the list
	UINT32 uiNumberOfNodesInList = 0;
	CFOR_EACH_PLAYER_IN_GROUP(p, g) ++uiNumberOfNodesInList;
	f->write(&uiNumberOfNodesInList, sizeof(UINT32));

	// Loop through and save only the players profile id
	CFOR_EACH_PLAYER_IN_GROUP(p, g)
	{
		// Save the ubProfile ID for this node
		const UINT32 uiProfileID = p->pSoldier->ubProfile;
		f->write(&uiProfileID, sizeof(UINT32));
	}
}