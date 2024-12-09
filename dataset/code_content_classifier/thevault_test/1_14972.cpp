static INT32 GetFundsOnMerc(SOLDIERTYPE const& s)
{
	INT32 iCurrentAmount = 0;
	// run through mercs pockets, if any money in them, add to total

	// run through grunts pockets and count all the spare change
	CFOR_EACH_SOLDIER_INV_SLOT(i, s)
	{
		if (GCM->getItem(i->usItem)->getItemClass() == IC_MONEY)
		{
			iCurrentAmount += i->uiMoneyAmount;
		}
	}

	return iCurrentAmount;
}