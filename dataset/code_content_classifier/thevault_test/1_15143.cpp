FOR_EACH_IN_TEAM(s, CREATURE_TEAM)
	{
		// Are we ALIVE.....
		if (s->bLife > 0)
		{
			// For sure for flag thet they are dead is not set
			// Check for any more badguys
			// ON THE STRAGETY LAYER KILL BAD GUYS!

			// HELLO!  THESE ARE CREATURES!  THEY CAN'T BE NEUTRAL!
			//if (!s->bNeutral && s->bSide != OUR_TEAM)
			{
				gTacticalStatus.ubAttackBusyCount++;
				EVENT_SoldierGotHit(s, 0, 10000, 0, s->bDirection, 320, NULL, FIRE_WEAPON_NO_SPECIAL, s->bAimShotLocation, NOWHERE);
			}
		}
	}