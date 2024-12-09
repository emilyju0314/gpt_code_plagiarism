void HandleGlobalLoyaltyEvent( UINT8 ubEventType, INT16 sSectorX, INT16 sSectorY, INT8 bSectorZ)
{
	INT32 iLoyaltyChange;
	INT8 bTownId = 0;

	if( bSectorZ == 0 )
	{
		// grab town id, if this event occured within one
		bTownId = GetTownIdForSector(SECTOR(sSectorX, sSectorY));
	}

	// should other towns ignore events occuring in this town?
	if( bTownId == SAN_MONA )
	{
		return;
	}

	// determine what the base loyalty change of this event type is worth
	// these are ->hundredths<- of loyalty points, so choose appropriate values accordingly!
	// the closer a town is to the event, the more pronounced the effect upon that town is
	switch (ubEventType)
	{
		case GLOBAL_LOYALTY_BATTLE_WON:
			CheckConditionsForTriggeringCreatureQuest( sSectorX, sSectorY, bSectorZ );
			iLoyaltyChange = 500;
			break;
		case GLOBAL_LOYALTY_QUEEN_BATTLE_WON:
			CheckConditionsForTriggeringCreatureQuest( sSectorX, sSectorY, bSectorZ );
			iLoyaltyChange = 1000;
			break;
		case GLOBAL_LOYALTY_BATTLE_LOST:
			iLoyaltyChange = -750;
			break;
		case GLOBAL_LOYALTY_ENEMY_KILLED:
			iLoyaltyChange = 50;
			break;
		case GLOBAL_LOYALTY_NATIVE_KILLED:
			// note that there is special code (much more severe) for murdering civilians in the currently loaded sector.
			// this event is intended more for processing militia casualties, and the like
			iLoyaltyChange = -50;
			break;
		case GLOBAL_LOYALTY_ABANDON_MILITIA:
			// it doesn't matter how many of them are being abandoned
			iLoyaltyChange = -750;
			break;
		case GLOBAL_LOYALTY_GAIN_TOWN_SECTOR:
			iLoyaltyChange = 500;
			break;
		case GLOBAL_LOYALTY_LOSE_TOWN_SECTOR:
			iLoyaltyChange = -1000;
			break;
		case GLOBAL_LOYALTY_LIBERATE_WHOLE_TOWN:
			iLoyaltyChange = 1000;
			break;
		case GLOBAL_LOYALTY_GAIN_MINE:
			iLoyaltyChange = 1000;
			break;
		case GLOBAL_LOYALTY_LOSE_MINE:
			iLoyaltyChange = -1500;
			break;
		case GLOBAL_LOYALTY_GAIN_SAM:
			iLoyaltyChange = 250;
			break;
		case GLOBAL_LOYALTY_LOSE_SAM:
			iLoyaltyChange = -250;
			break;

		default:
			Assert(FALSE);
			return;
	}

	AffectAllTownsLoyaltyByDistanceFrom( iLoyaltyChange, sSectorX, sSectorY, bSectorZ);
}