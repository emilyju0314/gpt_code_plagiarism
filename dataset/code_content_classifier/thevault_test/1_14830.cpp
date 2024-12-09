FOR_EACH_WORLD_BOMB(wb)
	{
		if (wb.iItemIndex != iItemIndex) continue;

		wb.fExists = FALSE;
		return;
	}