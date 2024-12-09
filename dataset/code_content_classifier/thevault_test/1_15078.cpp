FOR_EACH_IN_TEAM(pGoon, CIV_TEAM)
		{
			if (pGoon->ubCivilianGroup == KINGPIN_CIV_GROUP &&
				pGoon->bInSector &&
				pGoon->bLife >= OKLIFE &&
				pGoon->bOppList[pSoldier->ubID] == SEEN_CURRENTLY)
			{
				MakeCivHostile( pGoon, 2 );
				if ( ! (gTacticalStatus.uiFlags & INCOMBAT) )
				{
					EnterCombatMode( pGoon->bTeam );
				}
			}
		}