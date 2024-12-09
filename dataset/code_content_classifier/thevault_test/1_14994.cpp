void DecrementTownLoyalty( INT8 bTownId, UINT32 uiLoyaltyDecrease )
{
	UINT32 uiRemainingDecrement;
	INT16 sThisDecrement;


	Assert( ( bTownId >= FIRST_TOWN ) && ( bTownId < NUM_TOWNS ) );

	// doesn't affect towns where player hasn't established a "presence" yet
	if (!gTownLoyalty[ bTownId ].fStarted)
	{
		return;
	}

	// modify loyalty change by town's individual attitude toward rebelling (20 is typical)
	uiLoyaltyDecrease *= 100;
	uiLoyaltyDecrease /= (5 * gubTownRebelSentiment[ bTownId ]);

	// this whole thing is a hack to avoid rolling over the -32 to 32k range on the sChange value
	// only do a maximum of 10000 pts at a time...
	uiRemainingDecrement = uiLoyaltyDecrease;
	while ( uiRemainingDecrement )
	{
		sThisDecrement = ( INT16 ) MIN( uiRemainingDecrement, 10000 );

		// down the gain value
		gTownLoyalty[ bTownId ].sChange -= sThisDecrement;
		// update town value now
		UpdateTownLoyaltyRating( bTownId );

		uiRemainingDecrement -= sThisDecrement;
	}
}