CFOR_EACH_PLAYER_IN_GROUP(p, g)
	{
		// Save the ubProfile ID for this node
		const UINT32 uiProfileID = p->pSoldier->ubProfile;
		f->write(&uiProfileID, sizeof(UINT32));
	}