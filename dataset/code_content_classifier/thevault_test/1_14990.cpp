FOR_EACH_SOLDIER_INV_SLOT(pObj, s)
		{
			if ( pObj->usItem != NOTHING )
			{
				// Check if it's supposed to be dropped
				if (!(pObj->fFlags & OBJECT_UNDROPPABLE)
					|| (s.bTeam == OUR_TEAM)
					|| gamepolicy(f_drop_everything))
				{
					// and make sure that it really is a droppable item type
					if ( !(GCM->getItem(pObj->usItem)->getFlags() & ITEM_DEFAULT_UNDROPPABLE) )
					{
						ReduceAmmoDroppedByNonPlayerSoldiers(s, *pObj);
						Visibility vis = gamepolicy(f_all_dropped_visible) ? VISIBLE : bVisible;
						AddItemToPool(s.sGridNo, pObj, vis, s.bLevel, usItemFlags, -1);
					}
				}
			}
		}