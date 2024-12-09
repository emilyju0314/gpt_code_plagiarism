static void AddTextToBlankSectorBox(PopUpBox* const box)
{
	UINT16 usSectorValue = 0;

	// get the sector value
	usSectorValue = SECTOR( bCurrentTownMineSectorX, bCurrentTownMineSectorY );

	ST::string title = GetSectorLandTypeString(usSectorValue, 0, true);

	AddMonoString(box, title);

	// blank line
	AddMonoString(box, ST::null);

	AddSectorToBox(box);
}