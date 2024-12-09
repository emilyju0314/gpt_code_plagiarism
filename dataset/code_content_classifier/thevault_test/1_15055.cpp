static UINT8 GetPopupIndexFromMousePosition(void)
{
	UINT8 ubNumEntriesDown;
	UINT16 usRelX;
	UINT8 ubCount;
	if( gusMouseXPos >= gPopup.usLeft
		&& gusMouseXPos <= gPopup.usRight
		&& gusMouseYPos > gPopup.usTop						//one pixel gap on top ignored
		&& gusMouseYPos < gPopup.usBottom - 2 )		//two pixel gap on bottom ignored
	{
		//subtract the top y coord of the popup region from the mouse's yPos as well
		//as an extra pixel at the top of the region which is ignored in menu selection,
		//divide this number by the height of a menu entry, then add one.  This will
		//return the menu index from 1 (at the top) to n (at the bottom).
		ubNumEntriesDown = (gusMouseYPos - gPopup.usTop - 1) / gusEntryHeight + 1;
		usRelX = gusMouseXPos - gPopup.usLeft;
		ubCount=0;
		while( usRelX > gPopup.ubColumnWidth[ ubCount ] )
		{
			usRelX -= gPopup.ubColumnWidth[ ubCount ];
			ubCount++;
			ubNumEntriesDown += gPopup.ubMaxEntriesPerColumn;
		}
		if( ubNumEntriesDown >= gPopup.ubNumEntries )
			ubNumEntriesDown = gPopup.ubNumEntries;
		return ubNumEntriesDown;
	}
	return 0; //mouse not in valid region.
}