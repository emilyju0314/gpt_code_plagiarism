CFOR_EACH_WORLD_BOMB(wb)
	{
		WORLDITEM const& wi = GetWorldItem(wb.iItemIndex);
		if (wi.sGridNo != sGridNo) continue;

		OBJECTTYPE const& o = wi.o;
		if (o.usItem == SWITCH && !(o.fFlags & OBJECT_DISABLED_BOMB) && o.bDetonatorType == BOMB_SWITCH)
		{
			// send out a signal to detonate other bombs, rather than this which
			// isn't a bomb but a trigger

			// first set attack busy count to 0 in case of a lingering a.b.c. problem...
			gTacticalStatus.ubAttackBusyCount = 0;

			SetOffBombsByFrequency(s, o.bFrequency);
		}
	}