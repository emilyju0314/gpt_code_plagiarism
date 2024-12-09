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