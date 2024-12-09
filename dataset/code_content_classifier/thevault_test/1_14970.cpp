BOOLEAN RemoveNewlyHiredMercFromPersonnelDepartedList(UINT8 ubProfile)
{
	for (INT32 i = 0; i < 256; i++)
	{
		// are they already in the Dead list?
		if (LaptopSaveInfo.ubDeadCharactersList[i] == ubProfile)
		{
			//Reset the fact that they were once hired
			LaptopSaveInfo.ubDeadCharactersList[i] = -1;
			return TRUE;
		}

		// are they already in the other list?
		if (LaptopSaveInfo.ubLeftCharactersList[i] == ubProfile)
		{
			//Reset the fact that they were once hired
			LaptopSaveInfo.ubLeftCharactersList[i] = -1;
			return TRUE;
		}

		// are they already in the list?
		if (LaptopSaveInfo.ubOtherCharactersList[i] == ubProfile)
		{
			//Reset the fact that they were once hired
			LaptopSaveInfo.ubOtherCharactersList[i] = -1;
			return TRUE;
		}
	}

	return FALSE;
}