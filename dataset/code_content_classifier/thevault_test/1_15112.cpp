FOR_EACH_SOLDIERINITNODE(curr)
	{
		if (ubFreeSlots == 0 || ubNumCreatures == 0) break;
		if( !curr->pSoldier && curr->pBasicPlacement->bTeam == CREATURE_TEAM )
		{
			//Randomly determine if we will use this slot; the more available slots in proportion to
			//the number of enemies, the lower the chance of accepting the slot.
			if( ubFreeSlots <= ubNumCreatures || Random( ubFreeSlots ) < ubNumCreatures )
			{
				//Choose which team to use.
				iRandom = Random( ubNumCreatures );

				if( ubNumLarvae && iRandom < ubNumLarvae )
				{
					ubNumLarvae--;
					curr->pBasicPlacement->bBodyType = LARVAE_MONSTER;
				}
				else if( ubNumInfants && iRandom < ubNumLarvae + ubNumInfants )
				{
					ubNumInfants--;
					curr->pBasicPlacement->bBodyType = INFANT_MONSTER;
				}
				else if( ubNumYoungMales && iRandom < ubNumLarvae + ubNumInfants + ubNumYoungMales )
				{
					ubNumYoungMales--;
					curr->pBasicPlacement->bBodyType = YAM_MONSTER;
				}
				else if( ubNumYoungFemales && iRandom < ubNumLarvae + ubNumInfants + ubNumYoungMales + ubNumYoungFemales )
				{
					ubNumYoungFemales--;
					curr->pBasicPlacement->bBodyType = YAF_MONSTER;
				}
				else if( ubNumAdultMales && iRandom < ubNumLarvae + ubNumInfants + ubNumYoungMales + ubNumYoungFemales + ubNumAdultMales )
				{
					ubNumAdultMales--;
					curr->pBasicPlacement->bBodyType = AM_MONSTER;
				}
				else if( ubNumAdultFemales && iRandom < ubNumLarvae + ubNumInfants + ubNumYoungMales + ubNumYoungFemales + ubNumAdultMales + ubNumAdultFemales )
				{
					ubNumAdultFemales--;
					curr->pBasicPlacement->bBodyType = ADULTFEMALEMONSTER;
				}
				else
					SLOGA("AddSoldierInitListCreatures: something wrong with random");
				if( curr->pDetailedPlacement )
				{ //delete the detailed placement information.
					delete curr->pDetailedPlacement;
					curr->pDetailedPlacement = NULL;
					curr->pBasicPlacement->fDetailedPlacement = FALSE;
				}
				if( AddPlacementToWorld( curr ) )
				{
					ubNumCreatures--;
				}
				else
				{
					return;
				}
			}
			ubFreeSlots--;
			//With the decrementing of the slot vars in this manner, the chances increase so that all slots
			//will be full by the time the end of the list comes up.
		}
	}