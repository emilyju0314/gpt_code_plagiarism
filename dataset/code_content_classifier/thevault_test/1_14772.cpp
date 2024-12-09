void SaveDoorTableToMap( HWFILE fp )
{
	size_t i = 0;

	while (i < DoorTable.size())
	{
		if (!OpenableAtGridNo( DoorTable[ i ].sGridNo ))
			RemoveDoorInfoFromTable( DoorTable[ i ].sGridNo );
		else
			i++;
	}
	Assert(DoorTable.size() <= UINT8_MAX);
	UINT8 numDoors = static_cast<UINT8>(DoorTable.size());
	fp->writeArray(numDoors, DoorTable.data());
}