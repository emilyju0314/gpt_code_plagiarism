UINT16 FindGridNoFromSweetSpotWithStructData( SOLDIERTYPE *pSoldier, UINT16 usAnimState, INT16 sSweetGridNo, INT8 ubRadius, UINT8 *pubDirection, BOOLEAN fClosestToMerc )
{
	INT16 sTop, sBottom;
	INT16 sLeft, sRight;
	INT16 cnt1, cnt2, cnt3;
	INT16 sGridNo;
	INT32 uiRange, uiLowestRange = 999999;
	INT16 sLowestGridNo=-1;
	INT32 leftmost;
	BOOLEAN fFound = FALSE;
	SOLDIERTYPE soldier;
	UINT8 ubSaveNPCAPBudget;
	UINT8 ubSaveNPCDistLimit;
	UINT8 ubBestDirection=0;

	//Save AI pathing vars.  changing the distlimit restricts how
	//far away the pathing will consider.
	ubSaveNPCAPBudget = gubNPCAPBudget;
	ubSaveNPCDistLimit = gubNPCDistLimit;
	gubNPCAPBudget = 0;
	gubNPCDistLimit = ubRadius;

	//create dummy soldier, and use the pathing to determine which nearby slots are
	//reachable.
	soldier = SOLDIERTYPE{};
	soldier.bLevel = 0;
	soldier.bTeam = 1;
	soldier.sGridNo = sSweetGridNo;

	sTop    = ubRadius;
	sBottom = -ubRadius;
	sLeft   = - ubRadius;
	sRight  = ubRadius;

	// If we are already at this gridno....
	if ( pSoldier->sGridNo == sSweetGridNo && !( pSoldier->uiStatusFlags & SOLDIER_VEHICLE ) )
	{
		*pubDirection = pSoldier->bDirection;
		return( sSweetGridNo );
	}

	//clear the mapelements of potential residue MAPELEMENT_REACHABLE flags
	//in the square region.
	// ATE: CHECK FOR BOUNDARIES!!!!!!
	for( cnt1 = sBottom; cnt1 <= sTop; cnt1++ )
	{
		leftmost = ( ( sSweetGridNo + ( WORLD_COLS * cnt1 ) )/ WORLD_COLS ) * WORLD_COLS;

		for( cnt2 = sLeft; cnt2 <= sRight; cnt2++ )
		{
			sGridNo = sSweetGridNo + ( WORLD_COLS * cnt1 ) + cnt2;
			if( sGridNo >=0 && sGridNo < WORLD_MAX && sGridNo >= leftmost && sGridNo < ( leftmost + WORLD_COLS ) )
			{
				gpWorldLevelData[ sGridNo ].uiFlags &= (~MAPELEMENT_REACHABLE);
			}
		}
	}

	//Now, find out which of these gridnos are reachable
	//(use the fake soldier and the pathing settings)
	FindBestPath( &soldier, NOWHERE, 0, WALKING, COPYREACHABLE, ( PATH_IGNORE_PERSON_AT_DEST | PATH_THROUGH_PEOPLE ) );

	uiLowestRange = 999999;

	for( cnt1 = sBottom; cnt1 <= sTop; cnt1++ )
	{
		leftmost = ( ( sSweetGridNo + ( WORLD_COLS * cnt1 ) )/ WORLD_COLS ) * WORLD_COLS;

		for( cnt2 = sLeft; cnt2 <= sRight; cnt2++ )
		{
			sGridNo = sSweetGridNo + ( WORLD_COLS * cnt1 ) + cnt2;
			if( sGridNo >=0 && sGridNo < WORLD_MAX && sGridNo >= leftmost &&
				sGridNo < ( leftmost + WORLD_COLS )
				&& gpWorldLevelData[ sGridNo ].uiFlags & MAPELEMENT_REACHABLE )
			{
				// Go on sweet stop
				if ( NewOKDestination( pSoldier, sGridNo, TRUE, pSoldier->bLevel ) )
				{
					BOOLEAN fDirectionFound = FALSE;
					UINT16  usOKToAddStructID;
					UINT16  usAnimSurface;

					if ( pSoldier->pLevelNode != NULL )
					{
						if ( pSoldier->pLevelNode->pStructureData != NULL )
						{
							usOKToAddStructID = pSoldier->pLevelNode->pStructureData->usStructureID;
						}
						else
						{
							usOKToAddStructID = INVALID_STRUCTURE_ID;
						}
					}
					else
					{
						usOKToAddStructID = INVALID_STRUCTURE_ID;
					}

					// Get animation surface...
					usAnimSurface = DetermineSoldierAnimationSurface( pSoldier, usAnimState );
					// Get structure ref...
					const STRUCTURE_FILE_REF* const pStructureFileRef = GetAnimationStructureRef(pSoldier, usAnimSurface, usAnimState);
					Assert(pStructureFileRef);

					// Check each struct in each direction
					for( cnt3 = 0; cnt3 < 8; cnt3++ )
					{
						if (OkayToAddStructureToWorld(sGridNo, pSoldier->bLevel, &pStructureFileRef->pDBStructureRef[OneCDirection(cnt3)], usOKToAddStructID))
						{
							fDirectionFound = TRUE;
							break;
						}

					}

					if ( fDirectionFound )
					{
						if ( fClosestToMerc )
						{
							uiRange = FindBestPath( pSoldier, sGridNo, pSoldier->bLevel, pSoldier->usUIMovementMode, NO_COPYROUTE, 0 );

							if (uiRange == 0 )
							{
								uiRange = 999;
							}
						}
						else
						{
							uiRange = GetRangeInCellCoordsFromGridNoDiff( sSweetGridNo, sGridNo );
						}

						if ( uiRange < uiLowestRange )
						{
							ubBestDirection = (UINT8)cnt3;
							sLowestGridNo = sGridNo;
							uiLowestRange = uiRange;
							fFound = TRUE;
						}
					}
				}
			}
		}
	}
	gubNPCAPBudget = ubSaveNPCAPBudget;
	gubNPCDistLimit = ubSaveNPCDistLimit;
	if ( fFound )
	{
		// Set direction we chose...
		*pubDirection = ubBestDirection;

		return( sLowestGridNo );
	}
	else
	{
		return( NOWHERE );
	}
}