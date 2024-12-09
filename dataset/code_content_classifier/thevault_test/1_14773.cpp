void AddDoorInfoToTable( DOOR *pDoor )
{
	FOR_EACH_DOOR(d)
	{
		if (d.sGridNo != pDoor->sGridNo) continue;
		d = *pDoor;
		return;
	}

	//no existing door found, so add a new one.
	DoorTable.push_back(*pDoor);
}