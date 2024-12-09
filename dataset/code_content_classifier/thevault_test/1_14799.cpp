FOR_EACH_SOLDIERINITNODE_SAFE(curr)
	{
		BASIC_SOLDIERCREATE_STRUCT const* const bp = curr->pBasicPlacement;
		if (bp->fPriorityExistance)
			continue;
		if (bp->bTeam != tempDetailedPlacement.bTeam)
			continue;
		SOLDIERCREATE_STRUCT       const* const dp = curr->pDetailedPlacement;
		if (dp && dp->ubProfile != NO_PROFILE)
			continue;
		RemoveSoldierNodeFromInitList(curr);
	}