CFOR_EACH_WORLD_BOMB(wb)
	{
		OBJECTTYPE& o = GetWorldItem(wb.iItemIndex).o;
		if (o.bDetonatorType == BOMB_REMOTE)
		{
			// Found a remote bomb, so check to see if it has the same frequency
			if (o.bFrequency == bFrequency)
			{
				// toggle its active flag
				if (o.fFlags & OBJECT_DISABLED_BOMB)
				{
					o.fFlags &= ~OBJECT_DISABLED_BOMB;
				}
				else
				{
					o.fFlags |= OBJECT_DISABLED_BOMB;
				}
			}
		}
	}