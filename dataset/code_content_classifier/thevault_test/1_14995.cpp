static void UpdateTownLoyaltyRating(INT8 bTownId)
{
	// check gain value and update loyaty
	UINT8 ubOldLoyaltyRating = 0;
	INT16 sRatingChange = 0;
	UINT8 ubMaxLoyalty = 0;


	Assert( ( bTownId >= FIRST_TOWN ) && ( bTownId < NUM_TOWNS ) );

	// remember previous loyalty value
	ubOldLoyaltyRating = gTownLoyalty[ bTownId ].ubRating;

	sRatingChange = gTownLoyalty[ bTownId ].sChange / GAIN_PTS_PER_LOYALTY_PT;

	// if loyalty is ready to increase
	if( sRatingChange > 0 )
	{
		// if the town is Omerta, and the rebels are/will become hostile
		if ((bTownId == OMERTA) && (gTacticalStatus.fCivGroupHostile[ REBEL_CIV_GROUP ] != CIV_GROUP_NEUTRAL))
		{
			// maximum loyalty is much less than normal
			ubMaxLoyalty = HOSTILE_OMERTA_LOYALTY_RATING;
		}
		else
		{
			ubMaxLoyalty = MAX_LOYALTY_VALUE;
		}

		// check if we'd be going over the max
		if( (gTownLoyalty[ bTownId ].ubRating + sRatingChange ) >= ubMaxLoyalty )
		{
			// set to max and null out gain pts
			gTownLoyalty[ bTownId ].ubRating = ubMaxLoyalty;
			gTownLoyalty[ bTownId ].sChange = 0;
		}
		else
		{
			// increment loyalty rating, reduce sChange
			gTownLoyalty[ bTownId ].ubRating += sRatingChange;
			gTownLoyalty[ bTownId ].sChange %= GAIN_PTS_PER_LOYALTY_PT;
		}
	}
	else
	// if loyalty is ready to decrease
	if( sRatingChange < 0 )
	{
		// check if we'd be going below zero
		if( ( gTownLoyalty[ bTownId ].ubRating + sRatingChange ) < 0 )
		{
			// set to zero and null out gain pts
			gTownLoyalty[ bTownId ].ubRating = 0;
			gTownLoyalty[ bTownId ].sChange = 0;
		}
		else
		{
			// decrement loyalty rating, reduce sChange
			gTownLoyalty[ bTownId ].ubRating += sRatingChange;
			gTownLoyalty[ bTownId ].sChange %= GAIN_PTS_PER_LOYALTY_PT;
		}
	}


	// check old aginst new, if diff, dirty map panel
	if( ubOldLoyaltyRating != gTownLoyalty[ bTownId ].ubRating )
	{
		fMapPanelDirty = TRUE;
	}
}