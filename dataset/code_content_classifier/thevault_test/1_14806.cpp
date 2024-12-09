CFOR_EACH_SOLDIERINITNODE(curr)
		{
			if( curr->pDetailedPlacement )
			{
				curr->pBasicPlacement->fPriorityExistance = TRUE;
			}
		}