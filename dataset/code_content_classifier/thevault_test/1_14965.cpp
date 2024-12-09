void UpdateItemStatsPanel()
{
	SetFontAttributes(FONT10ARIAL, FONT_GRAY2);
	if( gpItem && iCurrentTaskbar == TASK_ITEMS &&
			gbEditingMode != EDITING_TRIGGERS && gbEditingMode != EDITING_ACTIONITEMS )
	{
		MPrint(500, EDITOR_TASKBAR_POS_Y +  6, "Toggle hide flag");
	}
	SetFontForeground( FONT_YELLOW );
	switch( gbEditingMode )
	{
		case EDITING_NOTHING:
			if( iCurrentTaskbar == TASK_ITEMS )
				MPrint(520, EDITOR_TASKBAR_POS_Y + 40, "No item selected.");
			else
			{
				MPrint(500, EDITOR_TASKBAR_POS_Y + 30, "Slot available for");
				MPrint(500, EDITOR_TASKBAR_POS_Y + 40, "random generation.");
			}
			return;
		case EDITING_KEYS:
			if( !gpEditingItemPool )
			{
				MPrint(500, EDITOR_TASKBAR_POS_Y + 40, "Keys not editable.");
				return;
			}
			break;
		case EDITING_OWNERSHIP:
			MPrint(512, EDITOR_TASKBAR_POS_Y + 24, "ProfileID of owner");
			return;
		case EDITING_NOT_YET_IMPLEMENTED:
			MPrint(500, EDITOR_TASKBAR_POS_Y + 40, "Item class not implemented.");
			return;
		case EDITING_DROPPABLE:
			MPrint(500, EDITOR_TASKBAR_POS_Y + 40, "Slot locked as empty.");
			return;
		case EDITING_GUNS:
			MPrint(512, EDITOR_TASKBAR_POS_Y + 24, "Status");
			MPrint(512, EDITOR_TASKBAR_POS_Y + 44, "Rounds");
			MPrint(512, EDITOR_TASKBAR_POS_Y + 64, "Trap Level");
			break;
		case EDITING_AMMO:
			MPrint(512, EDITOR_TASKBAR_POS_Y + 24, "Quantity");
			MPrint(512, EDITOR_TASKBAR_POS_Y + 44, "Trap Level");
			break;
		case EDITING_ARMOUR:
		case EDITING_EQUIPMENT:
			MPrint(512, EDITOR_TASKBAR_POS_Y + 24, "Status");
			MPrint(512, EDITOR_TASKBAR_POS_Y + 44, "Trap Level");
			break;
		case EDITING_EXPLOSIVES:
			MPrint(512, EDITOR_TASKBAR_POS_Y + 20, "Status");
			MPrint(512, EDITOR_TASKBAR_POS_Y + 44, "Quantity");
			MPrint(512, EDITOR_TASKBAR_POS_Y + 64, "Trap Level");
			break;
		case EDITING_MONEY:
			MPrint(532, EDITOR_TASKBAR_POS_Y + 24, "Dollars");
			break;
		case EDITING_ACTIONITEMS:
			MPrint(512, EDITOR_TASKBAR_POS_Y +  9, "Status");
			MPrint(512, EDITOR_TASKBAR_POS_Y + 29, "Trap Level");
			break;
		case EDITING_TRIGGERS:
			MPrint(512, EDITOR_TASKBAR_POS_Y +  9, "Trap Level");
			MPrint(512, EDITOR_TASKBAR_POS_Y + 29, "Tolerance");
			if (gpEditingItemPool && gpItem->bFrequency >= PANIC_FREQUENCY_3)
				MPrint(500, EDITOR_TASKBAR_POS_Y + 47, "Alarm Trigger");
			break;
	}
	if( gpEditingItemPool )
	{
		const INT32 iPercent = 100 - GetWorldItem(gpEditingItemPool->iItemIndex).ubNonExistChance;
		if( iPercent == 100 )
			SetFontForeground( FONT_YELLOW );
		else if( iPercent >= 50 )
			SetFontForeground( FONT_ORANGE );
		else
			SetFontForeground( FONT_RED );
		MPrint(512, EDITOR_TASKBAR_POS_Y + 84, "Exist Chance");
		MPrint(587, EDITOR_TASKBAR_POS_Y +  6, "B");
		MPrint(609, EDITOR_TASKBAR_POS_Y +  6, "R");
		MPrint(630, EDITOR_TASKBAR_POS_Y +  6, "S");
	}
	InvalidateRegion( 477, EDITOR_TASKBAR_POS_Y +  2, 161, 97 );
}