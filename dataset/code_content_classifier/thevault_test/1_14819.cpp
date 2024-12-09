FOR_EACH_IN_TEAM(pSoldier, OUR_TEAM)
	{
		// If we are controllable
		if (OkControllableMerc(pSoldier) && pSoldier->bAssignment == CurrentSquad())
		{
			//Need to keep a copy of a good soldier, so we can access it later, and
			//not more than once.
			pValidSoldier = pSoldier;

			ubNumControllableMercs++;

			//We need to keep track of the number of EPCs and mercs in this squad.  If we have
			//only one merc and one or more EPCs, then we can't allow the merc to tactically traverse,
			//if he is the only merc near enough to traverse.
			if( AM_AN_EPC( pSoldier ) )
			{
				ubNumEPCs++;
				//Also record the EPC's slot ID incase we later build a string using the EPC's name.
				gPotentiallyAbandonedEPC = pSoldier;
				if( AM_A_ROBOT( pSoldier ) && !CanRobotBeControlled( pSoldier ) )
				{
					gfRobotWithoutControllerAttemptingTraversal = TRUE;
					ubNumControllableMercs--;
					continue;
				}
			}
			else
			{
				ubNumMercs++;
			}

			if ( SoldierOKForSectorExit( pSoldier, bExitDirection, usAdditionalData ) )
			{
				fAtLeastOneMercControllable++;

				if (pSoldier == sel) fOnlySelectedGuy = TRUE;
			}
			else
			{
				GROUP *pGroup;

				// ATE: Dont's assume exit grids here...
				if ( bExitDirection != -1 )
				{
					//Now, determine if this is a valid path.
					pGroup = GetGroup( pValidSoldier->ubGroupID );
					AssertMsg( pGroup, String( "%s is not in a valid group (pSoldier->ubGroupID is %d)", pValidSoldier->name.c_str(), pValidSoldier->ubGroupID) );
					UINT32 traverse_time = TRAVERSE_TIME_IMPOSSIBLE;
					if( !gbWorldSectorZ )
					{
						traverse_time = GetSectorMvtTimeForGroup((UINT8)SECTOR(pGroup->ubSectorX, pGroup->ubSectorY), bExitDirection, pGroup);
					}
					else if( gbWorldSectorZ > 1 )
					{ //We are attempting to traverse in an underground environment.  We need to use a complete different
						//method.  When underground, all sectors are instantly adjacent.
						traverse_time = UndergroundTacticalTraversalTime(bExitDirection);
					}
					if (puiTraverseTimeInMinutes) *puiTraverseTimeInMinutes = traverse_time;
					if (traverse_time == TRAVERSE_TIME_IMPOSSIBLE)
					{
						gfInvalidTraversal = TRUE;
						return FALSE;
					}
				}
				else
				{
					// Exit grid travel is instantaneous
					if (puiTraverseTimeInMinutes) *puiTraverseTimeInMinutes = 0;
				}
			}
		}
	}