static void ResetMovementForEnemyGroup(GROUP* pGroup)
{
	//Validate that the group is an enemy group and that it is moving.
	if( pGroup->fPlayer )
	{
		return;
	}
	if( !pGroup->fBetweenSectors || !pGroup->ubNextX || !pGroup->ubNextY )
	{ //Reset the group's assignment by moving it to the group's original sector as it's pending group.
		RepollSAIGroup( pGroup );
		return;
	}

	//Cancel the event that is posted.
	DeleteStrategicEvent( EVENT_GROUP_ARRIVAL, pGroup->ubGroupID );

	//Calculate the new arrival time (all data pertaining to movement should be valid)
	if( pGroup->uiTraverseTime > 400 )
	{ //The group was likely sleeping which makes for extremely long arrival times.  Shorten it
		//arbitrarily.  Doesn't really matter if this isn't accurate.
		pGroup->uiTraverseTime = 90;
	}
	pGroup->setArrivalTime(GetWorldTotalMin() + pGroup->uiTraverseTime);

	//Add a new event
	AddStrategicEvent( EVENT_GROUP_ARRIVAL, pGroup->uiArrivalTime, pGroup->ubGroupID );
}