CFOR_EACH_IN_TEAM(pSoldier, OUR_TEAM)
		{
			if (pSoldier->bLife    != 0 &&
					pSoldier->sSectorX == sSectorX &&
					pSoldier->sSectorY == sSectorY &&
					pSoldier->bSectorZ == bSectorZ &&
					!pSoldier->fBetweenSectors )
			{
				return TRUE;
			}
		}