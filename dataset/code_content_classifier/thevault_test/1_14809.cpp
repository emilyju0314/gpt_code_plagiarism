CFOR_EACH_SOLDIERINITNODE(curr)
	{
		if( curr->pDetailedPlacement )
		{
			for( i = 0; i < NUM_INV_SLOTS; i++ )
			{
				pItem = &curr->pDetailedPlacement->Inv[ i ];
				if( pItem->usItem != NONE )
				{
					//case 1 (see above)
					pItem->fFlags |= OBJECT_NO_OVERWRITE;
				}
				else if( !(pItem->fFlags & OBJECT_UNDROPPABLE) )
				{
					//case 2 (see above)
					pItem->fFlags |= OBJECT_NO_OVERWRITE;
				}
			}
		}
	}