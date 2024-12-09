CFOR_EACH_WORLD_BOMB(wb)
	{
		WORLDITEM& wi = GetWorldItem(wb.iItemIndex);
		if (wi.sGridNo != sGridNo) continue;

		OBJECTTYPE& o = wi.o;
		if (o.bDetonatorType == BOMB_PRESSURE)
		{
			// Found a pressure item
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