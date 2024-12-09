bool
CChangeSetBuilder::isUnique (CRange &inRange)
{
	size_t dataSize = mData.size ();
	size_t rangeSize = inRange.size ();

	for (size_t i = 0; i <= dataSize - rangeSize; i++)
	{
		if (i == inRange.mL)
		{
			continue;
		}
		
		size_t j;

		for (j = 0; j < rangeSize  &&
			mData [inRange.mL + j]->compare (* mData [i + j] ) == 0; j++)
		{
		}

		if (j == rangeSize)
		{
			return false;		// matched!
		}
	}

	return true;
}