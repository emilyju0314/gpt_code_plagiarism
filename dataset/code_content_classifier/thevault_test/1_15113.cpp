FOR_EACH_SOLDIERINITNODE(curr)
	{
		if( curr->pSoldier && !curr->pSoldier->bActive )
		{
			curr->ubSoldierID = 0;
		}
		hfile->write(&curr->ubNodeID,    1);
		hfile->write(&curr->ubSoldierID, 1);
	}