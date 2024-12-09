FOR_EACH_WORLD_BOMB(wb)
	{
		OBJECTTYPE const& o = GetWorldItem(wb.iItemIndex).o;
		if (o.bDetonatorType != BOMB_TIMED || o.fFlags & OBJECT_DISABLED_BOMB) continue;

		return wb.iItemIndex;
	}