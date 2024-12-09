void AddSoldierInitListMilitia( UINT8 ubNumGreen, UINT8 ubNumRegs, UINT8 ubNumElites )
{
	SOLDIERINITNODE *mark;
	SOLDIERINITNODE *curr;
	INT32 iRandom;
	UINT8 ubMaxNum;
	BOOLEAN fDoPlacement;
	UINT8 ubEliteSlots = 0;
	UINT8 ubRegSlots = 0;
	UINT8 ubGreenSlots = 0;
	UINT8 ubFreeSlots;
	UINT8 *pCurrSlots=NULL;
	UINT8 *pCurrTotal=NULL;
	UINT8 ubCurrClass;

	ubMaxNum = ubNumGreen + ubNumRegs + ubNumElites;

	//Sort the list in the following manner:
	//-Priority placements first
	//-Basic placements next
	//-Any placements with existing soldiers last (overrides others)
	SortSoldierInitList();

	curr = gSoldierInitHead;

	//First fill up only the priority existance slots (as long as the availability and class are okay)
	while( curr && curr->pBasicPlacement->fPriorityExistance && ubMaxNum )
	{
		fDoPlacement = TRUE;

		if( curr->pBasicPlacement->bTeam == ENEMY_TEAM || curr->pBasicPlacement->bTeam == MILITIA_TEAM )
		{
			//Matching team (kindof), now check the soldier class...
			if( ubNumElites && curr->pBasicPlacement->ubSoldierClass == SOLDIER_CLASS_ELITE )
			{
				curr->pBasicPlacement->ubSoldierClass = SOLDIER_CLASS_ELITE_MILITIA;
				ubNumElites--;
			}
			else if( ubNumRegs && curr->pBasicPlacement->ubSoldierClass == SOLDIER_CLASS_ARMY )
			{
				curr->pBasicPlacement->ubSoldierClass = SOLDIER_CLASS_REG_MILITIA;
				ubNumRegs--;
			}
			else if( ubNumGreen && curr->pBasicPlacement->ubSoldierClass == SOLDIER_CLASS_ADMINISTRATOR )
			{
				curr->pBasicPlacement->ubSoldierClass = SOLDIER_CLASS_GREEN_MILITIA;
				ubNumGreen--;
			}
			else
				fDoPlacement = FALSE;

			if ( fDoPlacement )
			{
				curr->pBasicPlacement->bTeam = MILITIA_TEAM;
				curr->pBasicPlacement->bOrders = STATIONARY;
				curr->pBasicPlacement->bAttitude = (INT8) Random( MAXATTITUDES );
				if( curr->pDetailedPlacement )
				{
					//delete the detailed placement information.
					delete curr->pDetailedPlacement;
					curr->pDetailedPlacement = NULL;
					curr->pBasicPlacement->fDetailedPlacement = FALSE;
					RandomizeRelativeLevel( &( curr->pBasicPlacement->bRelativeAttributeLevel ), curr->pBasicPlacement->ubSoldierClass );
					RandomizeRelativeLevel( &( curr->pBasicPlacement->bRelativeEquipmentLevel ), curr->pBasicPlacement->ubSoldierClass );
				}
				if( AddPlacementToWorld( curr ) )
				{
					ubMaxNum--;
				}
				else
					return;
			}
		}
		curr = curr->next;
	}
	if( !ubMaxNum )
		return;
	//Now count the number of nodes that are basic placements of desired team AND CLASS
	//This information will be used to randomly determine which of these placements
	//will be added based on the number of slots we can still add.
	mark = curr;
	while( curr && !curr->pSoldier )
	{
		if( curr->pBasicPlacement->bTeam == ENEMY_TEAM || curr->pBasicPlacement->bTeam == MILITIA_TEAM )
		{
			switch( curr->pBasicPlacement->ubSoldierClass )
			{
				case SOLDIER_CLASS_ELITE:         ubEliteSlots++; break;
				case SOLDIER_CLASS_ADMINISTRATOR: ubGreenSlots++; break;
				case SOLDIER_CLASS_ARMY:          ubRegSlots++;   break;
			}
		}
		curr = curr->next;
	}

	//we now have the numbers of available slots for each soldier class, so loop through three times
	//and randomly choose some (or all) of the matching slots to fill.  This is done randomly.
	for( ubCurrClass = SOLDIER_CLASS_ADMINISTRATOR; ubCurrClass <= SOLDIER_CLASS_ARMY; ubCurrClass++ )
	{
		//First, prepare the counters.
		switch( ubCurrClass )
		{
			case SOLDIER_CLASS_ADMINISTRATOR:
				pCurrSlots = &ubGreenSlots;
				pCurrTotal = &ubNumGreen;
				break;
			case SOLDIER_CLASS_ELITE:
				pCurrSlots = &ubEliteSlots;
				pCurrTotal = &ubNumElites;
				break;
			case SOLDIER_CLASS_ARMY:
				pCurrSlots = &ubRegSlots;
				pCurrTotal = &ubNumRegs;
				break;
		}
		//Now, loop through the basic placement of the list.
		curr = mark; //mark is the marker where the basic placements start.
		while( curr && !curr->pSoldier && ubMaxNum && *pCurrTotal && *pCurrSlots )
		{
			if( curr->pBasicPlacement->bTeam == ENEMY_TEAM || curr->pBasicPlacement->bTeam == MILITIA_TEAM )
			{
				if( curr->pBasicPlacement->ubSoldierClass == ubCurrClass )
				{
					if( *pCurrSlots <= *pCurrTotal || Random( *pCurrSlots ) < *pCurrTotal )
					{
						curr->pBasicPlacement->bTeam = MILITIA_TEAM;
						curr->pBasicPlacement->bOrders = STATIONARY;
						switch( ubCurrClass )
						{
							case SOLDIER_CLASS_ADMINISTRATOR:
								curr->pBasicPlacement->ubSoldierClass = SOLDIER_CLASS_GREEN_MILITIA;
								break;
							case SOLDIER_CLASS_ARMY:
								curr->pBasicPlacement->ubSoldierClass = SOLDIER_CLASS_REG_MILITIA;
								break;
							case SOLDIER_CLASS_ELITE:
								curr->pBasicPlacement->ubSoldierClass = SOLDIER_CLASS_ELITE_MILITIA;
								break;
						}
						//found matching team, so add this soldier to the game.
						if( AddPlacementToWorld( curr ) )
						{
							(*pCurrTotal)--;
							ubMaxNum--;
						}
						else
							return;
					}
					(*pCurrSlots)--;
					//With the decrementing of the slot vars in this manner, the chances increase so that all slots
					//will be full by the time the end of the list comes up.
				}
			}
			curr = curr->next;
		}
	}
	if( !ubMaxNum )
		return;
	//If we are at this point, that means that there are some compatibility issues.  This is fine.  An example
	//would be a map containing 1 elite placement, and 31 troop placements.  If we had 3 elites move into this
	//sector, we would not have placements for two of them.  What we have to do is override the class information
	//contained in the list by choosing unused placements, and assign them to the elites.  This time, we will
	//use all free slots including priority placement slots (ignoring the priority placement information).

	//First, count up the total number of free slots.
	ubFreeSlots = 0;
	CFOR_EACH_SOLDIERINITNODE(curr)
	{
		if(!curr->pSoldier &&
			(curr->pBasicPlacement->bTeam == ENEMY_TEAM ||
			curr->pBasicPlacement->bTeam == MILITIA_TEAM))
		{
			ubFreeSlots++;
		}
	}

	//Now, loop through the entire list again, but for the last time.  All enemies will be inserted now ignoring
	//detailed placements and classes.
	FOR_EACH_SOLDIERINITNODE(curr)
	{
		if (ubFreeSlots == 0 || ubMaxNum == 0) break;
		if(!curr->pSoldier &&
			(curr->pBasicPlacement->bTeam == ENEMY_TEAM ||
			curr->pBasicPlacement->bTeam == MILITIA_TEAM))
		{
			//Randomly determine if we will use this slot; the more available slots in proportion to
			//the number of enemies, the lower the chance of accepting the slot.
			if( ubFreeSlots <= ubMaxNum || Random( ubFreeSlots ) < ubMaxNum )
			{
				//Choose which team to use.
				iRandom = Random( ubMaxNum );
				if( iRandom < ubNumElites )
				{
					curr->pBasicPlacement->ubSoldierClass = SOLDIER_CLASS_ELITE_MILITIA;
					ubNumElites--;
				}
				else if( iRandom < ubNumElites + ubNumRegs )
				{
					curr->pBasicPlacement->ubSoldierClass = SOLDIER_CLASS_REG_MILITIA;
					ubNumRegs--;
				}
				else if( iRandom < ubNumElites + ubNumRegs + ubNumGreen )
				{
					curr->pBasicPlacement->ubSoldierClass = SOLDIER_CLASS_GREEN_MILITIA;
					ubNumGreen--;
				}
				else
					SLOGE(
						"AddSoldierInitListMilitia: something wrong with random");
				curr->pBasicPlacement->bTeam = MILITIA_TEAM;
				curr->pBasicPlacement->bOrders = STATIONARY;
				curr->pBasicPlacement->bAttitude = (INT8) Random( MAXATTITUDES );
				if( curr->pDetailedPlacement )
				{
					//delete the detailed placement information.
					delete curr->pDetailedPlacement;
					curr->pDetailedPlacement = NULL;
					curr->pBasicPlacement->fDetailedPlacement = FALSE;
					RandomizeRelativeLevel( &( curr->pBasicPlacement->bRelativeAttributeLevel), curr->pBasicPlacement->ubSoldierClass );
					RandomizeRelativeLevel( &( curr->pBasicPlacement->bRelativeEquipmentLevel), curr->pBasicPlacement->ubSoldierClass );
				}
				if( AddPlacementToWorld( curr ) )
				{
					ubMaxNum--;
				}
				else
					return;
			}
			ubFreeSlots--;
			//With the decrementing of the slot vars in this manner, the chances increase so that all slots
			//will be full by the time the end of the list comes up.
		}
	}
}