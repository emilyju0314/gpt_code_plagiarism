static FLOAT DiffFromNormRatio(INT16 sThisValue, INT16 sNormalValue)
{
	FLOAT flRatio;

	if (sThisValue > 0)
	{
		flRatio = (FLOAT) sNormalValue / sThisValue;

		// restrict each ratio to within a reasonable range
		if (flRatio < MIN_INSURANCE_RATIO)
		{
			flRatio = MIN_INSURANCE_RATIO;
		}
		else
		if (flRatio > MAX_INSURANCE_RATIO)
		{
			flRatio = MAX_INSURANCE_RATIO;
		}
	}
	else
	{
		// use maximum allowable ratio
		flRatio = MAX_INSURANCE_RATIO;
	}

	return( flRatio );
}