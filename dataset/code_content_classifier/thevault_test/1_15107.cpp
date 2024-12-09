FOR_EACH_SOLDIERINITNODE(curr)
		{
			if (ubMaxNum == 0 ||
				*pCurrTotal == 0 ||
				*pCurrSlots == 0 ||
				curr->pDetailedPlacement == NULL ||
				!curr->pBasicPlacement->fPriorityExistance)
			{
				break;
			}
			if( !curr->pSoldier && curr->pBasicPlacement->bTeam == ENEMY_TEAM )
			{
				if( curr->pBasicPlacement->ubSoldierClass == ubCurrClass )
				{
					if( *pCurrSlots <= *pCurrTotal || Random( *pCurrSlots ) < *pCurrTotal )
					{
						//found matching team, so add this soldier to the game.
						if( AddPlacementToWorld( curr ) )
						{
							(*pCurrTotal)--;
							ubMaxNum--;
						}
						else
							return;
					}
					(*pCurrSlots)--;
					//With the decrementing of the slot vars in this manner, the chances increase so that all slots
					//will be full by the time the end of the list comes up.
				}
			}
			curr = curr->next;
		}