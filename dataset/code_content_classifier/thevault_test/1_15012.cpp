static void AddSectorToBox(PopUpBox* const box)
{
	ST::string wString;
	ST::string wString2;

	// sector
	wString = ST::format("{}:", pwMiscSectorStrings[ 1 ]);
	AddMonoString(box, wString);

	wString = GetShortSectorString(bCurrentTownMineSectorX, bCurrentTownMineSectorY);
	if (bCurrentTownMineSectorZ != 0 )
	{
		wString2 = ST::format("-{}", bCurrentTownMineSectorZ);
		wString += wString2;
	}

	AddSecondColumnMonoString(box, wString);
}