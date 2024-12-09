bool ModifyDoorStatus(GridNo const gridno, BOOLEAN const is_open, BOOLEAN const perceived_open)
{
	// Find the base tile for the door structure and use that gridno
	STRUCTURE* const structure = FindStructure(gridno, STRUCTURE_ANYDOOR);
	if (!structure) return false;

	STRUCTURE* const base = FindBaseStructure(structure);
	if (!base) return false;
	GridNo const base_gridno = base->sGridNo;

	// Check to see if the user is adding an existing door
	FOR_EACH_DOOR_STATUS(d)
	{
		if (d.sGridNo != base_gridno) continue;

		// Set the status
		if (perceived_open != DONTSETDOORSTATUS)
		{
			if (perceived_open)
				d.ubFlags |= DOOR_PERCEIVED_OPEN;
			else
				d.ubFlags &= ~DOOR_PERCEIVED_OPEN;

			// Turn off perceived not set flag
			d.ubFlags &= ~DOOR_PERCEIVED_NOTSET;
		}

		if (is_open != DONTSETDOORSTATUS)
		{
			if (is_open)
				d.ubFlags |= DOOR_OPEN;
			else
				d.ubFlags &= ~DOOR_OPEN;
		}

		return true;
	}

	// Add a new door status structure
	gpDoorStatus.push_back(DOOR_STATUS{});

	DOOR_STATUS& d = gpDoorStatus.back();
	d.sGridNo = base_gridno;

	// Init the flags
	d.ubFlags = 0;

	if (is_open) d.ubFlags |= DOOR_OPEN;

	// if a new door, use same as actual
	if (perceived_open == DONTSETDOORSTATUS)
	{
		d.ubFlags |= DOOR_PERCEIVED_NOTSET;
	}
	else if (is_open)
	{
		d.ubFlags |= DOOR_PERCEIVED_OPEN;
	}

	// Flag the tile as containing a door status
	gpWorldLevelData[base_gridno].ubExtFlags[0] |= MAPELEMENT_EXT_DOOR_STATUS_PRESENT;
	return true;
}