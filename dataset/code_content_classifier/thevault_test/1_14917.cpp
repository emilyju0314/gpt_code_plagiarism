void SetFactTrue(Fact const usFact)
{
	// This function is here just for control flow purposes (debug breakpoints)
	// and code is more readable that way

	// must intercept when Jake is first trigered to start selling fuel
	if (usFact == FACT_ESTONI_REFUELLING_POSSIBLE && !CheckFact(usFact, 0))
	{
		// give him some gas...
		GuaranteeAtLeastXItemsOfIndex( ARMS_DEALER_JAKE, GAS_CAN, ( UINT8 ) ( 4 + Random( 3 ) ) );
	}

	gubFact[usFact] = TRUE;
}