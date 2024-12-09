void SetTownLoyalty( INT8 bTownId, UINT8 ubNewLoyaltyRating )
{
	Assert( ( bTownId >= FIRST_TOWN ) && ( bTownId < NUM_TOWNS ) );

	// if the town does use loyalty
	if (gfTownUsesLoyalty[ bTownId ])
	{
		gTownLoyalty[ bTownId ].ubRating = ubNewLoyaltyRating;
		gTownLoyalty[ bTownId ].sChange = 0;

		// this is just like starting the loyalty if it happens first
		gTownLoyalty[ bTownId ].fStarted = TRUE;
	}
}