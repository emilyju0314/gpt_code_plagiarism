DOOR* FindDoorInfoAtGridNo( INT32 iMapIndex )
{
	FOR_EACH_DOOR(d)
	{
		if (d.sGridNo == iMapIndex) return &d;
	}
	return NULL;
}