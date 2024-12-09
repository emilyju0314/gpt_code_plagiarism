DOOR_STATUS* GetDoorStatus(INT16 const sGridNo)
{
	if (gpDoorStatus.empty()) return 0;

	// Find the base tile for the door structure and use that gridno
	STRUCTURE* const structure = FindStructure(sGridNo, STRUCTURE_ANYDOOR);
	if (!structure) return 0;
	STRUCTURE const* const base = FindBaseStructure(structure);
	if (!base) return 0;

	FOR_EACH_DOOR_STATUS(d)
	{
		if (d.sGridNo == base->sGridNo) return &d;
	}

	return 0;
}