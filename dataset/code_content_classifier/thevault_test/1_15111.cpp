FOR_EACH_SOLDIERINITNODE(curr)
	{
		if (!curr->pBasicPlacement->fPriorityExistance || ubNumCreatures == 0) break;
		fDoPlacement = TRUE;

		if( curr->pBasicPlacement->bTeam == CREATURE_TEAM )
		{
			//Matching team, now check the soldier class...
			if( ubNumLarvae && curr->pBasicPlacement->bBodyType == LARVAE_MONSTER )
				ubNumLarvae--;
			else if( ubNumInfants && curr->pBasicPlacement->bBodyType == INFANT_MONSTER )
				ubNumInfants--;
			else if( ubNumYoungMales && curr->pBasicPlacement->bBodyType == YAM_MONSTER )
				ubNumYoungMales--;
			else if( ubNumYoungFemales && curr->pBasicPlacement->bBodyType == YAF_MONSTER )
				ubNumYoungFemales--;
			else if( ubNumAdultMales && curr->pBasicPlacement->bBodyType == AM_MONSTER )
				ubNumAdultMales--;
			else if( ubNumAdultFemales && curr->pBasicPlacement->bBodyType == ADULTFEMALEMONSTER )
				ubNumAdultFemales--;
			else
				fDoPlacement = FALSE;
			if ( fDoPlacement )
			{
				if( AddPlacementToWorld( curr ) )
				{
					ubNumCreatures--;
				}
				else
					return;
			}
		}
	}