static const ST::string GetPopupMenuString(UINT8 ubIndex)
{
	switch( gPopup.ubPopupMenuID )
	{
		case CHANGETSET_POPUP: //tile sets
			return gTilesets[ ubIndex ].zName;
		case OWNERSHIPGROUP_POPUP: //civilian groups
		case CHANGECIVGROUP_POPUP: //civilian groups
			return gszCivGroupNames[ ubIndex ];
		case SCHEDULEACTION_POPUP: //setting scheduling actions
			return gszScheduleActions[ ubIndex ];
		case ACTIONITEM_POPUP:
			return gszActionItemDesc[ ubIndex ];
		default:
			return ST::null;
	}
}