CFOR_EACH_WORLD_BOMB(wb)
	{
		WORLDITEM  const& wi = GetWorldItem(wb.iItemIndex);
		OBJECTTYPE const& o  = wi.o;

		INT8 bPanicIndex;
		switch (o.bFrequency)
		{
			case PANIC_FREQUENCY:   bPanicIndex = 0; break;
			case PANIC_FREQUENCY_2: bPanicIndex = 1; break;
			case PANIC_FREQUENCY_3: bPanicIndex = 2; break;
			default:                continue;
		}

		if (o.usItem == SWITCH)
		{
			INT16                  sGridNo = wi.sGridNo;
			const STRUCTURE* const switch_ = FindStructure(sGridNo, STRUCTURE_SWITCH);
			if (switch_)
			{
				switch (switch_->ubWallOrientation)
				{
					case INSIDE_TOP_LEFT:
					case OUTSIDE_TOP_LEFT:  sGridNo += DirectionInc(SOUTH); break;
					case INSIDE_TOP_RIGHT:
					case OUTSIDE_TOP_RIGHT: sGridNo += DirectionInc(EAST);  break;

					default: break;
				}
			}

			gTacticalStatus.fPanicFlags                      |= PANIC_TRIGGERS_HERE;
			gTacticalStatus.sPanicTriggerGridNo[bPanicIndex]  = sGridNo;
			gTacticalStatus.ubPanicTolerance[bPanicIndex]     = o.ubTolerance;
			if (o.fFlags & OBJECT_ALARM_TRIGGER)
			{
				gTacticalStatus.bPanicTriggerIsAlarm[bPanicIndex] = TRUE;
			}
			if (bPanicIndex + 1 == NUM_PANIC_TRIGGERS) return;
		}
		else
		{
			gTacticalStatus.fPanicFlags |= PANIC_BOMBS_HERE;
		}
	}