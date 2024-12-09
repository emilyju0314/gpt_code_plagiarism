CFOR_EACH_SOLDIERINITNODE(curr)
			{
				if( curr->pBasicPlacement->bTeam == CIV_TEAM && !curr->pDetailedPlacement )
				{
					curr->pBasicPlacement->ubSoldierClass = SOLDIER_CLASS_MINER;
					curr->pBasicPlacement->bBodyType      = BODY_RANDOM;
				}
			}