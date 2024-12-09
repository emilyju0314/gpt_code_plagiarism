void InitPopupMenu(GUIButtonRef const button, PopupMenuID const ubPopupMenuID, UINT8 const ubDirection)
{
	UINT16 usX, usY; // HACK000E
	UINT16 usMenuHeight;
	UINT16 usMenuWidth = 0;
	UINT16 usCurrStrWidth;
	UINT8 ubColumn, ubEntry;
	UINT8 ubCounter;
	//calculate the location of the menu based on the button position.
	//This also calculates the menu's direction based on position.

	gPopup.usFont = SMALLFONT1;
	gusEntryHeight = GetFontHeight( gPopup.usFont );

	switch( ubDirection )
	{
		case DIR_UPRIGHT:
			usX = button->X();
			usY = button->Y();
			break;
		case DIR_UPLEFT:
			usX = button->BottomRightX();
			usY = button->Y();
			break;
		case DIR_DOWNRIGHT:
			usX = button->X();
			usY = button->BottomRightY();
			break;
		case DIR_DOWNLEFT:
			usX = button->BottomRightX();
			usY = button->BottomRightY();
			break;

		default: abort(); // HACK000E
	}

	//Decipher the PopupMenuID
	switch( ubPopupMenuID )
	{
		case CHANGETSET_POPUP:	//change tileset
			gPopup.ubNumEntries = gubNumTilesets;
			break;
		case OWNERSHIPGROUP_POPUP:
		case CHANGECIVGROUP_POPUP:
			gPopup.ubNumEntries = NUM_CIV_GROUPS;
			break;
		case SCHEDULEACTION_POPUP:
			gPopup.ubNumEntries = NUM_SCHEDULE_ACTIONS;
			break;
		case ACTIONITEM_POPUP:
			gPopup.ubNumEntries = NUM_ACTIONITEMS;
			break;
		default:
			return;
	}

	gPopup.usFont = SMALLFONT1;
	gusEntryHeight = GetFontHeight( gPopup.usFont );

	gPopup.ubPopupMenuID = ubPopupMenuID;
	gPopup.ubSelectedIndex = 0;
	gPopup.ubActiveType = POPUP_ACTIVETYPE_NOT_YET_DETERMINED;
	gPopup.fActive = TRUE;
	fWaitingForLButtonRelease = FALSE;
	gPopup.fUseKeyboardInfoUntilMouseMoves = FALSE;
	//Initialize the last mouse position to be out of bounds.
	gPopup.usLastMouseX = 1000;
	gPopup.usLastMouseY = 1000;
	//clear the column widths.
	for( ubColumn = 0; ubColumn < MAX_COLUMNS; ubColumn++ )
		gPopup.ubColumnWidth[ ubColumn ] = 0;

	//1) Calc total entry height of the popup region.
	gPopup.ubColumns = 1;
	gPopup.ubMaxEntriesPerColumn = gPopup.ubNumEntries;
	usMenuHeight = gPopup.ubNumEntries * gusEntryHeight + 3;
	while ((usMenuHeight                 >= usY && (ubDirection == DIR_UPLEFT   || ubDirection == DIR_UPRIGHT)) ||
		(SCREEN_HEIGHT - usMenuHeight >= usY && (ubDirection == DIR_DOWNLEFT || ubDirection == DIR_DOWNRIGHT)))
	{ //menu has too many entries.  Increase the number of columns until the height is
		//less than the max height.
		gPopup.ubMaxEntriesPerColumn = (gPopup.ubNumEntries+gPopup.ubColumns)/(gPopup.ubColumns+1);
		usMenuHeight = gPopup.ubMaxEntriesPerColumn * gusEntryHeight + 3;
		gPopup.ubColumns++;
	}
	//now we have the number of columns as well as the max number of entries per column, and
	//the total menu height.

	//We now calculate the total width of the menu as well as the max width of each column.
	ubCounter = 0;
	usMenuWidth = 0;
	for( ubColumn = 0; ubColumn < gPopup.ubColumns; ubColumn++ )
	{
		for( ubEntry = 0; ubEntry < gPopup.ubMaxEntriesPerColumn; ubEntry++ )
		{
			if( ubCounter >= gPopup.ubNumEntries )
				break; //done (don't want to process undefined entries...)
			usCurrStrWidth = 16 + StringPixLength( GetPopupMenuString( ubCounter ) , gPopup.usFont );
			if( usCurrStrWidth > gPopup.ubColumnWidth[ ubColumn ] )
			{
				gPopup.ubColumnWidth[ ubColumn ] = (UINT8)usCurrStrWidth;
			}
			ubCounter++;
		}
		usMenuWidth += gPopup.ubColumnWidth[ ubColumn ];
	}

	//Calculate popup menu boundaries based on direction from argument point.
	switch( ubDirection )
	{
		case DIR_UPRIGHT:
			gPopup.usLeft = usX;
			gPopup.usTop = usY - usMenuHeight - 1;
			gPopup.usRight = usX + usMenuWidth;
			gPopup.usBottom = usY - 1;
			break;
		case DIR_UPLEFT:
			gPopup.usLeft = usX - usMenuWidth;
			gPopup.usTop = usY - usMenuHeight - 1;
			gPopup.usRight = usX;
			gPopup.usBottom = usY - 1;
			break;
		case DIR_DOWNRIGHT:
			gPopup.usLeft = usX;
			gPopup.usTop = usY + 1;
			gPopup.usRight = usX + usMenuWidth;
			gPopup.usBottom = usY + usMenuHeight + 1;
			break;
		case DIR_DOWNLEFT:
			gPopup.usLeft = usX - usMenuWidth;
			gPopup.usTop = usY + 1;
			gPopup.usRight = usX;
			gPopup.usBottom = usY + usMenuHeight + 1;
			break;
	}
	MSYS_DefineRegion(&popupRegion, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, MSYS_PRIORITY_HIGHEST, CURSOR_NORMAL, MSYS_NO_CALLBACK, MSYS_NO_CALLBACK);

	RenderPopupMenu();
}