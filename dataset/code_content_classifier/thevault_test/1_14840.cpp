static void CheckForValidArrivalSector(void)
{
	INT16   sTop, sBottom;
	INT16   sLeft, sRight;
	INT16   cnt1, cnt2;
	UINT8   ubRadius = 4;
	INT32   leftmost;
	INT16   sSectorGridNo, sSectorGridNo2;
	INT32   uiRange, uiLowestRange = 999999;
	BOOLEAN fFound = FALSE;
	ST::string sString;
	ST::string zShortTownIDString1;
	ST::string zShortTownIDString2;

	sSectorGridNo = SECTOR_INFO_TO_STRATEGIC_INDEX(g_merc_arrive_sector);

	// Check if valid...
	if ( !StrategicMap[ sSectorGridNo ].fEnemyControlled )
	{
		return;
	}

	zShortTownIDString1 = GetShortSectorString(SECTORX(g_merc_arrive_sector), SECTORY(g_merc_arrive_sector));


	// If here - we need to do a search!
	sTop    = ubRadius;
	sBottom = -ubRadius;
	sLeft   = - ubRadius;
	sRight  = ubRadius;

	INT16 sGoodX = 0; // XXX HACK000E
	INT16 sGoodY = 0; // XXX HACK000E
	for( cnt1 = sBottom; cnt1 <= sTop; cnt1++ )
	{
		leftmost = ( ( sSectorGridNo + ( MAP_WORLD_X * cnt1 ) )/ MAP_WORLD_X ) * MAP_WORLD_X;

		for( cnt2 = sLeft; cnt2 <= sRight; cnt2++ )
		{
			sSectorGridNo2 = sSectorGridNo + ( MAP_WORLD_X * cnt1 ) + cnt2;

			if( sSectorGridNo2 >=1 && sSectorGridNo2 < ( ( MAP_WORLD_X - 1 ) * ( MAP_WORLD_X - 1 ) ) && sSectorGridNo2 >= leftmost && sSectorGridNo2 < ( leftmost + MAP_WORLD_X ) )
			{
				if ( !StrategicMap[ sSectorGridNo2 ].fEnemyControlled && !StrategicMap[ sSectorGridNo2 ].fEnemyAirControlled )
				{
					uiRange = StrategicPythSpacesAway( sSectorGridNo2, sSectorGridNo );

					if ( uiRange < uiLowestRange )
					{
						sGoodY = cnt1;
						sGoodX = cnt2;
						uiLowestRange = uiRange;
						fFound = TRUE;
					}
				}
			}
		}
	}

	if ( fFound )
	{
		g_merc_arrive_sector = SECTOR(SECTORX(g_merc_arrive_sector) + sGoodX, SECTORY(g_merc_arrive_sector) + sGoodY);

		UpdateAnyInTransitMercsWithGlobalArrivalSector( );

		zShortTownIDString2 = GetShortSectorString(SECTORX(g_merc_arrive_sector), SECTORY(g_merc_arrive_sector));

		sString = st_format_printf(str_arrival_rerouted, zShortTownIDString2, zShortTownIDString1);

		DoScreenIndependantMessageBox(  sString, MSG_BOX_FLAG_OK, NULL );

	}
}