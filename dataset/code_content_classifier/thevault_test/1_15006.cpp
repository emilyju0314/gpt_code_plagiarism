CFOR_EACH_IN_TEAM(s, OUR_TEAM)
	{
		// Check if this guy is OK to control....
		if (OkControllableMerc(s) && !(s->uiStatusFlags & (SOLDIER_VEHICLE | SOLDIER_PASSENGER | SOLDIER_DRIVER)))
		{
			// Get screen pos of gridno......
			GetGridNoScreenXY(s->sGridNo, &sScreenX, &sScreenY);

			// ATE: If we are in a hiehger interface level, subttrasct....
			if ( gsInterfaceLevel == 1 )
			{
				sScreenY -= 50;
			}

			if (IsPointInScreenRect(sScreenX, sScreenY, aRect))
			{
				fAtLeastOne = TRUE;
			}
		}
	}