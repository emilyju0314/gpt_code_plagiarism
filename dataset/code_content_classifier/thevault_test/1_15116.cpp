FOR_EACH_SOLDIERINITNODE(i)
	{
		SOLDIERINITNODE&            si = *i;
		BASIC_SOLDIERCREATE_STRUCT& bp = *si.pBasicPlacement;
		if (bp.bTeam != ENEMY_TEAM) continue;
		if (!si.pDetailedPlacement) continue;

		delete si.pDetailedPlacement;
		si.pDetailedPlacement = 0;
		bp.fDetailedPlacement = FALSE;
		bp.fPriorityExistance = FALSE;
		bp.bBodyType          = BODY_RANDOM;
		RandomizeRelativeLevel(&bp.bRelativeAttributeLevel, bp.ubSoldierClass);
		RandomizeRelativeLevel(&bp.bRelativeEquipmentLevel, bp.ubSoldierClass);
	}