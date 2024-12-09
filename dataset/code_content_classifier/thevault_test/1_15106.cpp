CFOR_EACH_SOLDIERINITNODE(curr)
	{
		if (curr->pSoldier) break;
		if( curr->pBasicPlacement->bTeam == ENEMY_TEAM )
		{
			switch( curr->pBasicPlacement->ubSoldierClass )
			{
				case SOLDIER_CLASS_ELITE:
					if( curr->pBasicPlacement->fPriorityExistance && curr->pDetailedPlacement )
						ubElitePDSlots++;
					else if( curr->pBasicPlacement->fPriorityExistance )
						ubElitePSlots++;
					else if( curr->pDetailedPlacement )
						ubEliteDSlots++;
					else
						ubEliteBSlots++;
					break;
				case SOLDIER_CLASS_ADMINISTRATOR:
					if( curr->pBasicPlacement->fPriorityExistance && curr->pDetailedPlacement )
						ubAdminPDSlots++;
					else if( curr->pBasicPlacement->fPriorityExistance )
						ubAdminPSlots++;
					else if( curr->pDetailedPlacement )
						ubAdminDSlots++;
					else
						ubAdminBSlots++;
					break;
				case SOLDIER_CLASS_ARMY:
					if( curr->pBasicPlacement->fPriorityExistance && curr->pDetailedPlacement )
						ubTroopPDSlots++;
					else if( curr->pBasicPlacement->fPriorityExistance )
						ubTroopPSlots++;
					else if( curr->pDetailedPlacement )
						ubTroopDSlots++;
					else
						ubTroopBSlots++;
					break;
			}
		}
	}