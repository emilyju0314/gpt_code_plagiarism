void LoadDoorTableFromMap(HWFILE const f)
{
	TrashDoorTable();

	UINT8 numDoors = 0;
	f->read(&numDoors, sizeof(numDoors));
	if (numDoors == 0) return;

	DoorTable.assign(numDoors, DOOR{});
	f->read(DoorTable.data(), sizeof(DOOR) * numDoors);

	// OK, reset perceived values to nothing...
	FOR_EACH_DOOR(d)
	{
		d.bPerceivedLocked  = DOOR_PERCEIVED_UNKNOWN;
		d.bPerceivedTrapped = DOOR_PERCEIVED_UNKNOWN;
	}
}