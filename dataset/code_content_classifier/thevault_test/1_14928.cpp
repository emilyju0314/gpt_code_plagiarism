FOR_EACH_SOLDIER(pTSoldier)
	{
		if (pTSoldier->service_partner == pSoldier)
		{
			// END SERVICE!
			pSoldier->ubServiceCount--;

			pTSoldier->service_partner = NULL;

			if (gTacticalStatus.fAutoBandageMode)
			{
				pSoldier->auto_bandaging_medic = NULL;
				ActionDone(pTSoldier);
			}
			else
			{
				// don't use end aid animation in autobandage
				if (pTSoldier->bLife >= OKLIFE && pTSoldier->bBreath > 0 && fPlayEndAnim)
				{
					EVENT_InitNewSoldierAnim(pTSoldier, END_AID, 0, FALSE);
				}
			}
		}
	}