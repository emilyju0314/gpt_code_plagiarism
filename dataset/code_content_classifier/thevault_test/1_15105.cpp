CFOR_EACH_SOLDIERINITNODE(i)
		{
			BASIC_SOLDIERCREATE_STRUCT& bp = *i->pBasicPlacement;
			if (bp.bTeam != CIV_TEAM || i->pDetailedPlacement) continue;
			bp.ubSoldierClass = SOLDIER_CLASS_MINER;
			bp.bBodyType      = BODY_RANDOM;
		}