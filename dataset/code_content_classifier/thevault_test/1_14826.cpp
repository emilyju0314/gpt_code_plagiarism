static void AddStringToMapScreenMessageList(const ST::string& pString, UINT16 usColor, BOOLEAN fStartOfNewString)
{
	ScrollStringSt* const pStringSt = AddString(pString, usColor, fStartOfNewString);

	// Figure out which queue slot index we're going to use to store this
	// If queue isn't full, this is easy, if is is full, we'll re-use the oldest slot
	// Must always keep the wraparound in mind, although this is easy enough with a static, fixed-size queue.

	// always store the new message at the END index

	// check if slot is being used, if so, clear it up
	ScrollStringSt* const old = gMapScreenMessageList[gubEndOfMapScreenMessageList];
	if (old != NULL)
	{
		delete old;
	}

	// store the new message there
	gMapScreenMessageList[gubEndOfMapScreenMessageList] = pStringSt;

	// increment the end
	gubEndOfMapScreenMessageList = (gubEndOfMapScreenMessageList + 1) % 256;

	// if queue is full, end will now match the start
	if (gubEndOfMapScreenMessageList == gubStartOfMapScreenMessageList)
	{
		// if that's so, increment the start
		gubStartOfMapScreenMessageList = (gubStartOfMapScreenMessageList + 1) % 256;
	}
}