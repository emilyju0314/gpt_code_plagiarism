void IncrementTownLoyaltyEverywhere( UINT32 uiLoyaltyIncrease )
{
	INT8 bTownId;

	for( bTownId = FIRST_TOWN; bTownId < NUM_TOWNS; bTownId++ )
	{
		IncrementTownLoyalty( bTownId, uiLoyaltyIncrease );
	}
}