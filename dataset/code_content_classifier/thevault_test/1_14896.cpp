static void LoadPlayerGroupList(HWFILE const f, GROUP* const g)
{
	// Load the number of nodes in the player list
	UINT32 node_count;
	f->read(&node_count, sizeof(UINT32));

	PLAYERGROUP** anchor = &g->pPlayerList;
	for (UINT32 i = node_count; i != 0; --i)
	{
		PLAYERGROUP* const pg = new PLAYERGROUP{};

		UINT32 profile_id;
		f->read(&profile_id, sizeof(UINT32));

		SOLDIERTYPE* const s = FindSoldierByProfileIDOnPlayerTeam(profile_id);
		//Should never happen
		//Assert(s != NULL);
		pg->pSoldier = s;
		pg->next     = NULL;

		*anchor = pg;
		anchor  = &pg->next;
	}
}