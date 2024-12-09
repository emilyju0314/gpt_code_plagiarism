void HandleTownLoyaltyForNPCRecruitment( SOLDIERTYPE *pSoldier )
{
	UINT32 uiLoyaltyValue = 0;

	UINT8 const bTownId = GetTownIdForSector(SECTOR(pSoldier->sSectorX, pSoldier->sSectorY));

	// is the merc currently in their home town?
	if( bTownId == gMercProfiles[ pSoldier->ubProfile ].bTown )
	{
		// yep, value of loyalty bonus depends on his importance to this to town
		uiLoyaltyValue = MULTIPLIER_LOCAL_RPC_HIRED * gMercProfiles[ pSoldier->ubProfile ].bTownAttachment;

		// increment town loyalty gain
		IncrementTownLoyalty( bTownId, uiLoyaltyValue );

		// DESIGN QUESTION: How easy is it to abuse this bonus by repeatedly hiring the guy over & over
		// (at worst daily? even more often if terminated & rehired?)  (ARM)
	}
}