FOR_EACH(AIMSortInfo const, i, g_aim_sort_info)
	{
		const UINT16 x = AIM_SORT_SORT_BY_X + i->x + (i->align == LEFT_JUSTIFIED ? 14 : -AIM_SORT_ASC_DESC_WIDTH - 4);
		DrawTextToScreen(str_aim_sort_list[i->index], x, AIM_SORT_SORT_BY_Y + i->y + 2, AIM_SORT_ASC_DESC_WIDTH, AIM_SORT_FONT_SORT_TEXT, AIM_SORT_COLOR_SORT_TEXT, FONT_MCOLOR_BLACK, i->align);
	}