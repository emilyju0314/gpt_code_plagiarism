static void TacticalScreenMsg(UINT16 colour, UINT8 const priority, const ST::string& str)
{
	if (IsTimeBeingCompressed()) return;

	ST::string msg = str;

	switch (priority)
	{
		case MSG_DIALOG:    colour = DIALOGUE_COLOR;  break;
		case MSG_INTERFACE: colour = INTERFACE_COLOR; break;
	}

	WRAPPED_STRING* const head = LineWrap(TINYFONT1, LINE_WIDTH, msg);

	ScrollStringSt** anchor = &pStringS;
	while (*anchor) anchor = &(*anchor)->pNext;

	BOOLEAN new_string = TRUE;
	for (WRAPPED_STRING* i = head; i; i = i->pNextWrappedString)
	{
		ScrollStringSt* const tmp = AddString(i->codepoints, colour, new_string);
		*anchor    = tmp;
		anchor     = &tmp->pNext;
		new_string = FALSE;
	}

	ClearWrappedStrings(head);
}