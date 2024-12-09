void RemoveDoorInfoFromTable( INT32 iMapIndex )
{
	for (size_t i = 0; i < DoorTable.size(); i++)
	{
		if (DoorTable[ i ].sGridNo == iMapIndex)
		{
			DoorTable.erase(DoorTable.begin() + i);
			return;
		}
	}
}