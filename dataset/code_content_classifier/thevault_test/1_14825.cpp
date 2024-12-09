void MapScreenMessage(UINT16 usColor, UINT8 ubPriority, const ST::string& str)
{
	ST::string DestString = str;

	switch (ubPriority)
	{
		case MSG_UI_FEEDBACK:
			// An imeediate feedback message. Do something else!
			BeginUIMessage(FALSE, DestString);
			return;

		case MSG_SKULL_UI_FEEDBACK:
			BeginUIMessage(TRUE, DestString);
			return;

		case MSG_DEBUG:
#if defined _DEBUG
			DestString = ST::format("Debug: {}", DestString);
			usColor = DEBUG_COLOR;
#else
			return;
#endif

		case MSG_DIALOG:    usColor = DIALOGUE_COLOR;  break;
		case MSG_INTERFACE: usColor = INTERFACE_COLOR; break;
	}

	WRAPPED_STRING* pStringWrapperHead = LineWrap(MAP_SCREEN_MESSAGE_FONT, MAP_LINE_WIDTH, DestString);
	WRAPPED_STRING* pStringWrapper = pStringWrapperHead;
	if (!pStringWrapper) return;

	BOOLEAN fNewString = TRUE;
	do
	{
		AddStringToMapScreenMessageList(pStringWrapper->codepoints, usColor, fNewString);
		fNewString = FALSE;
		pStringWrapper = pStringWrapper->pNextWrappedString;
	}
	while (pStringWrapper != NULL);

	ClearWrappedStrings(pStringWrapperHead);

	MoveToEndOfMapScreenMessageList();
}