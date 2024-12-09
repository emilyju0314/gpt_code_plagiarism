CFOR_EACH_SOLDIERINITNODE(curr)
	{
		BASIC_SOLDIERCREATE_STRUCT* const bp = curr->pBasicPlacement;
		if (!bp->fPriorityExistance) continue;
		if (bp->bTeam != CIV_TEAM)   continue;
		bp->fPriorityExistance = FALSE;
	}