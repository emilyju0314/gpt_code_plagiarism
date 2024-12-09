FOR_EACH_SOLDIERINITNODE(curr)
	{
		if (ubFreeSlots == 0 || ubMaxNum == 0) break;
		if( !curr->pSoldier && curr->pBasicPlacement->bTeam == ENEMY_TEAM )
		{
			//Randomly determine if we will use this slot; the more available slots in proportion to
			//the number of enemies, the lower the chance of accepting the slot.
			if( ubFreeSlots <= ubMaxNum || Random( ubFreeSlots ) < ubMaxNum )
			{
				//Choose which team to use.
				iRandom = Random( ubMaxNum );
				if( iRandom < ubTotalElite )
				{
					curr->pBasicPlacement->ubSoldierClass = SOLDIER_CLASS_ELITE;
					ubTotalElite--;
				}
				else if( iRandom < ubTotalElite + ubTotalTroops )
				{
					curr->pBasicPlacement->ubSoldierClass = SOLDIER_CLASS_ARMY;
					ubTotalTroops--;
				}
				else if( iRandom < ubTotalElite + ubTotalTroops + ubTotalAdmin )
				{
					curr->pBasicPlacement->ubSoldierClass = SOLDIER_CLASS_ADMINISTRATOR;
					ubTotalAdmin--;
				}
				else
					SLOGA("AddSoldierInitListEnemyDefenceSoldiers: something wrong with random");
				/* DISABLE THE OVERRIDE FOR NOW...
				if( curr->pDetailedPlacement )
				{ //delete the detailed placement information.
					delete curr->pDetailedPlacement;
					curr->pDetailedPlacement = NULL;
					curr->pBasicPlacement->fDetailedPlacement = FALSE;
				}
				*/
				if( AddPlacementToWorld( curr ) )
				{
					ubMaxNum--;
				}
				else
					return;
			}
			ubFreeSlots--;
			//With the decrementing of the slot vars in this manner, the chances increase so that all slots
			//will be full by the time the end of the list comes up.
		}
	}