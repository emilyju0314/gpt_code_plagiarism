CFOR_EACH_IN_TEAM(s, OUR_TEAM)
		{ //If we have a live and valid soldier
			if (s->bLife != 0 &&
					!s->fBetweenSectors &&
					!IsMechanical(*s) &&
					!AM_AN_EPC(s) &&
					s->sSectorX == gWorldSectorX &&
					s->sSectorY == gWorldSectorY &&
					s->bSectorZ == gbWorldSectorZ)
			{
				return FALSE;
			}
		}