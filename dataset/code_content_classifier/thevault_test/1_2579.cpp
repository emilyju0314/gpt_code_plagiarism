size_t
CChangeSetProcessor::checkPattern()
{
	size_t dataSize = mData.size();
	size_t patternSize = mPattern.size();

	size_t position = -1;
	bool b_found = false;

	for (size_t i = 0; i <= dataSize - patternSize; i++)
	{
		size_t j;

		for (j = 0; j < patternSize  &&
			mPattern[j]->compare(mData[i + j]) == 0; j++)
		{
		}

		if (j == patternSize)
		{
			// Context is not unique? Output 1st line of it and bail out

			THROW_IF_WINFO(b_found, XAmbiguousContext, mPattern[0]->c_str());
			position = i;

			b_found = true;
		}
	}

	THROW_IF_NOT_WINFO(b_found, XContextNotFound, mPattern[0]->c_str());

	return position;
}