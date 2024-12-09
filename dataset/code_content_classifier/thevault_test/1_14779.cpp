CFOR_EACH_NON_PLAYER_SOLDIER(s)
	{
		if (!s->bInSector) continue;

		FOR_EACH_DOOR_STATUS(d)
		{
			// If open, close
			if (!(d.ubFlags & DOOR_OPEN)) continue;
			HandleDoorChangeFromGridNo(0, d.sGridNo, TRUE);
		}
		break;
	}