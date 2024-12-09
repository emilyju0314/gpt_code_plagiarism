static BOOLEAN WillShopKeeperRejectObjectsFromPlayer(INT8 bDealerId, INT8 bSlotId)
{
	BOOLEAN fRejected = TRUE;

	const INVENTORY_IN_SLOT* const o = &PlayersOfferArea[bSlotId];
	if (GCM->getItem(o->sItemIndex)->getItemClass() == IC_MONEY)
	{
		fRejected = FALSE;
	}
	else if (CanDealerTransactItem(gbSelectedArmsDealerID, o->sItemIndex, TRUE))
	{
		fRejected = FALSE;
	}

	else
	{
		fRejected = TRUE;
	}

	return( fRejected );
}