int LegalNPCDestination(SOLDIERTYPE *pSoldier, INT16 sGridno, UINT8 ubPathMode, UINT8 ubWaterOK, UINT8 fFlags)
{
	BOOLEAN fSkipTilesWithMercs;

	if ((sGridno < 0) || (sGridno >= GRIDSIZE))
	{
		return(FALSE);
	}

	// return false if gridno on different level from merc
	if ( GridNoOnVisibleWorldTile( pSoldier->sGridNo ) && gpWorldLevelData[ pSoldier->sGridNo ].sHeight != gpWorldLevelData[ sGridno ].sHeight )
	{
		return( FALSE );
	}

	// skip mercs if turnbased and adjacent AND not doing an IGNORE_PATH check (which is used almost exclusively by GoAsFarAsPossibleTowards)
	fSkipTilesWithMercs = (gfTurnBasedAI && ubPathMode != IGNORE_PATH && SpacesAway( pSoldier->sGridNo, sGridno ) == 1 );

	// if this gridno is an OK destination
	// AND the gridno is NOT in a tear-gassed tile when we have no gas mask
	// AND someone is NOT already standing there
	// AND we're NOT already standing at that gridno
	// AND the gridno hasn't been black-listed for us

	// Nov 28 98: skip people in destination tile if in turnbased
	if ( ( NewOKDestination(pSoldier, sGridno, fSkipTilesWithMercs, pSoldier->bLevel ) ) &&
		( !InGas( pSoldier, sGridno ) ) &&
		( sGridno != pSoldier->sGridNo ) &&
		( sGridno != pSoldier->sBlackList ) )
	/*
	if ( ( NewOKDestination(pSoldier, sGridno, FALSE, pSoldier->bLevel ) ) &&
		( !(gpWorldLevelData[ sGridno ].ubExtFlags[0] & (MAPELEMENT_EXT_SMOKE | MAPELEMENT_EXT_TEARGAS | MAPELEMENT_EXT_MUSTARDGAS)) || IsWearingHeadGear(*pSoldier, GASMASK)) &&
		( sGridno != pSoldier->sGridNo ) &&
		( sGridno != pSoldier->sBlackList ) )*/
	/*
	if ( ( NewOKDestination(pSoldier,sGridno,ALLPEOPLE, pSoldier->bLevel ) ) &&
		( !(gpWorldLevelData[ sGridno ].ubExtFlags[0] & (MAPELEMENT_EXT_SMOKE | MAPELEMENT_EXT_TEARGAS | MAPELEMENT_EXT_MUSTARDGAS)) || IsWearingHeadGear(*pSoldier, GASMASK)) &&
		( sGridno != pSoldier->sGridNo ) &&
		( sGridno != pSoldier->sBlackList ) )*/
	{

		// if water's a problem, and gridno is in a water tile (bridges are OK)
		if (!ubWaterOK && Water(sGridno))
			return(FALSE);

		// passed all checks, now try to make sure we can get there!
		switch (ubPathMode)
		{
			// if finding a path wasn't asked for (could have already been done,
			// for example), don't bother
			case IGNORE_PATH     :	return(TRUE);

			case ENSURE_PATH     :	if ( FindBestPath( pSoldier, sGridno, pSoldier->bLevel, WALKING, COPYROUTE, fFlags ) )
				{
					return(TRUE);        // legal destination
				}
				else // got this far, but found no clear path,
				{
					// so test fails
					return(FALSE);
				}
				// *** NOTE: movement mode hardcoded to WALKING !!!!!
			case ENSURE_PATH_COST:	return PlotPath(pSoldier, sGridno, FALSE, FALSE, WALKING, 0);

			default:
				return(FALSE);
		}
	}
	else  // something failed - didn't even have to test path
		return(FALSE);       	// illegal destination
}