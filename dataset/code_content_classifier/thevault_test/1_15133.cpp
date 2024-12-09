FOR_EACH_MERC(i)
		{
			SOLDIERTYPE& s = **i;
			if (s.bTeam == OUR_TEAM) continue;

			// Handle everything from getting breath back, to bleeding, etc.
			EVENT_BeginMercTurn(s);

			HandlePlayerServices(s);
		}