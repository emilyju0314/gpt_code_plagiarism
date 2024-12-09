BOOLEAN SetThisSectorAsEnemyControlled(INT16 const sMapX, INT16 const sMapY, INT8 const bMapZ)
{
	UINT16 usMapSector = 0;
	BOOLEAN fWasPlayerControlled = FALSE;
	INT8 bTownId = 0;
	UINT8 ubTheftChance;

	//KM : August 6, 1999 Patch fix
	//     This check was added because this function gets called when player mercs retreat from an unresolved
	//     battle between militia and enemies.  It will get called again AFTER autoresolve is finished.
	if( gfAutomaticallyStartAutoResolve )
	{
		return( FALSE );
	}

	if( bMapZ == 0 )
	{
		usMapSector = sMapX + ( sMapY * MAP_WORLD_X );

		fWasPlayerControlled = !StrategicMap[ usMapSector ].fEnemyControlled;

		StrategicMap[ usMapSector ].fEnemyControlled = TRUE;

		// if player lost control to the enemy
		if ( fWasPlayerControlled )
		{
			if( PlayerMercsInSector( (UINT8)sMapX, (UINT8)sMapY, (UINT8)bMapZ ) )
			{ //too premature:  Player mercs still in sector.
				return FALSE;
			}

			UINT8 const sector = SECTOR(sMapX, sMapY);
			// check if there's a town in the sector
			bTownId = StrategicMap[ usMapSector ].bNameId;

			// and it's a town
			if ((bTownId >= FIRST_TOWN) && (bTownId < NUM_TOWNS))
			{
				if (bMapZ == 0 && sector != SEC_J9 && sector != SEC_K4)
				{
					HandleMoraleEvent( NULL, MORALE_TOWN_LOST, sMapX, sMapY, bMapZ );
					HandleGlobalLoyaltyEvent( GLOBAL_LOYALTY_LOSE_TOWN_SECTOR, sMapX, sMapY, bMapZ );

					CheckIfEntireTownHasBeenLost( bTownId, sMapX, sMapY );
				}
			}

			// if the sector has a mine which is still worth something
			INT8 const mine_id = GetMineIndexForSector(sector);
			if (mine_id != -1 && GetTotalLeftInMine(mine_id) > 0)
			{
				QueenHasRegainedMineSector(mine_id);
				HandleMoraleEvent(NULL, MORALE_MINE_LOST, sMapX, sMapY, bMapZ);
				HandleGlobalLoyaltyEvent(GLOBAL_LOYALTY_LOSE_MINE, sMapX, sMapY, bMapZ);
			}

			// if it's a SAM site sector
			if( IsThisSectorASAMSector( sMapX, sMapY, bMapZ ) )
			{
				HandleMoraleEvent( NULL, MORALE_SAM_SITE_LOST, sMapX, sMapY, bMapZ );
				HandleGlobalLoyaltyEvent( GLOBAL_LOYALTY_LOSE_SAM, sMapX, sMapY, bMapZ );
			}

			// if it's a helicopter refueling site sector
			if (IsRefuelSiteInSector(usMapSector))
			{
				UpdateRefuelSiteAvailability( );
			}

			// ARM: this must be AFTER all resulting loyalty effects are resolved, or reduced mine income shown won't be accurate
			NotifyPlayerWhenEnemyTakesControlOfImportantSector(sMapX, sMapY, 0);
		}

		// NOTE: Stealing is intentionally OUTSIDE the fWasPlayerControlled branch.  This function gets called if new
		// enemy reinforcements arrive, and they deserve another crack at stealing what the first group missed! :-)

		// stealing should fail anyway 'cause there shouldn't be a temp file for unvisited sectors, but let's check anyway
		if (GetSectorFlagStatus(sMapX, sMapY, bMapZ, SF_ALREADY_VISITED))
		{
			// enemies can steal items left lying about (random chance).  The more there are, the more they take!
			ubTheftChance = 5 * NumEnemiesInAnySector( sMapX, sMapY, bMapZ );
			// max 90%, some stuff may just simply not get found
			if (ubTheftChance > 90 )
			{
				ubTheftChance = 90;
			}
			RemoveRandomItemsInSector( sMapX, sMapY, bMapZ, ubTheftChance );
		}

		// don't touch fPlayer flag for a surface sector lost to the enemies!
		// just because player has lost the sector doesn't mean he realizes it - that's up to our caller to decide!
	}

	//KM : Aug 11, 1999 -- Patch fix:  Relocated this check so it gets called everytime a sector changes hands,
	//     even if the sector isn't a SAM site.  There is a bug _somewhere_ that fails to update the airspace,
	//     even though the player controls it.
	UpdateAirspaceControl( );

	// redraw map/income if in mapscreen
	fMapPanelDirty = TRUE;
	fMapScreenBottomDirty = TRUE;

	return fWasPlayerControlled;
}