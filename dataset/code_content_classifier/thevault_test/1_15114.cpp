CFOR_EACH_SOLDIERINITNODE(curr)
		{
			if( curr->pBasicPlacement->bBodyType == BLOODCAT && curr->pSoldier )
				ubNumAdded++;  //already one here!
		}