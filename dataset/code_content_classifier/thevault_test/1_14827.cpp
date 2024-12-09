void AddMonoString(PopUpBox* box, const ST::string& str)
{
	INT32 iCounter = 0;

	// find first free slot in list
	for (iCounter = 0; iCounter < MAX_POPUP_BOX_STRING_COUNT && box->Text[iCounter] != NULL; iCounter++);

	if ( iCounter >= MAX_POPUP_BOX_STRING_COUNT )
	{
		// using too many text lines, or not freeing them up properly
		SLOGA("AddMonoString: too many text lines");
		return;
	}

	PopUpString* const pStringSt    = new PopUpString{};

	box->Text[iCounter]                      = pStringSt;
	box->Text[iCounter]->codepoints          = str.to_utf32();
	box->Text[iCounter]->fShadeFlag          = FALSE;
	box->Text[iCounter]->fHighLightFlag      = FALSE;
	box->Text[iCounter]->fSecondaryShadeFlag = FALSE;

	box->fUpdated = FALSE;
}