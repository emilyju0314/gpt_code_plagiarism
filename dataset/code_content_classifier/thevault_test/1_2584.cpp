void
CChangeSetBuilder::detectPattern (CRange &outRange)
{
	size_t dataSize = mData.size ();
	
	CRange initRange (outRange);

	bool extRight = true;
	
	// Try to extend pattern range to the left/right by moving bound on 1
	// until we found unique one
	
	while (! isUnique (outRange))
	{
		if ((extRight  ||  outRange.mL == 0)  &&  outRange.mR < dataSize)
		{
			outRange.mR ++;
			extRight = false;
		}
		else if (outRange.mL > 0)
		{
			outRange.mL --;
			extRight = true;
		}
		else THROW_WINFO (XRuntime, "detectPattern: bad flag flipping state");
	}
	
	if (outRange.size () <= 2)
	{
		// Nothing to do anymore

		return;
	}

	// Now we have unique pattern, then try to make it as small as possible
	
	CRange tmpRange (outRange);

	do 
	{
		// Store result
		
		outRange = tmpRange;

		// Which operation was the last?
		
		if (extRight)
		{
			// Last change happen on left bound, shrink it back
			
			tmpRange.mR --;
		}
		else
		{
			tmpRange.mL ++;
		}
	}
	while (tmpRange.isEnclose (initRange)  &&  isUnique (tmpRange));
}