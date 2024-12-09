void StopSoldier( SOLDIERTYPE *pSoldier )
{
	ReceivingSoldierCancelServices( pSoldier );
	GivingSoldierCancelServices( pSoldier );

	if ( !( gAnimControl[ pSoldier->usAnimState ].uiFlags & ANIM_STATIONARY ) )
	{
		//SoldierGotoStationaryStance( pSoldier );
		EVENT_StopMerc(pSoldier);
	}

	// Set desination
	pSoldier->sFinalDestination = pSoldier->sGridNo;

}