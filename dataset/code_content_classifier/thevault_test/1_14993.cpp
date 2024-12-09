void IncrementTownLoyalty( INT8 bTownId, UINT32 uiLoyaltyIncrease )
{
	UINT32 uiRemainingIncrement;
	INT16 sThisIncrement;


	Assert( ( bTownId >= FIRST_TOWN ) && ( bTownId < NUM_TOWNS ) );

	// doesn't affect towns where player hasn't established a "presence" yet
	if (!gTownLoyalty[ bTownId ].fStarted)
	{
		return;
	}

	// modify loyalty change by town's individual attitude toward rebelling (20 is typical)
	uiLoyaltyIncrease *= (5 * gubTownRebelSentiment[ bTownId ]);
	uiLoyaltyIncrease /= 100;


	// this whole thing is a hack to avoid rolling over the -32 to 32k range on the sChange value
	// only do a maximum of 10000 pts at a time...
	uiRemainingIncrement = uiLoyaltyIncrease;
	while ( uiRemainingIncrement )
	{
		sThisIncrement = ( INT16 ) MIN( uiRemainingIncrement, 10000 );

		// up the gain value
		gTownLoyalty[ bTownId ].sChange += (INT16) sThisIncrement;
		// update town value now
		UpdateTownLoyaltyRating( bTownId );

		uiRemainingIncrement -= sThisIncrement;
	}
}