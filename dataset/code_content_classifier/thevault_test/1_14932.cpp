static UINT8 HowManyBRItemsToOrder(UINT16 usItemIndex, UINT8 ubCurrentlyOnHand, UINT8 ubBobbyRayNewUsed)
{
	UINT8	ubItemsOrdered = 0;

	const DealerInventory *inv = ubBobbyRayNewUsed ? GCM->getBobbyRayUsedInventory() : GCM->getBobbyRayNewInventory();
	const ItemModel *item = GCM->getItem(usItemIndex);

	Assert(usItemIndex < MAXITEMS);
	// formulas below will fail if there are more items already in stock than optimal
	Assert(ubCurrentlyOnHand <= inv->getMaxItemAmount(item));
	Assert(ubBobbyRayNewUsed < BOBBY_RAY_LISTS);


	// decide if he can get stock for this item (items are reordered an entire batch at a time)
	if (ItemTransactionOccurs(ARMS_DEALER_BOBBYR, usItemIndex, DEALER_BUYING, ubBobbyRayNewUsed))
	{
		if (ubBobbyRayNewUsed == BOBBY_RAY_NEW)
		{
			ubItemsOrdered = HowManyItemsToReorder(inv->getMaxItemAmount(item), ubCurrentlyOnHand);
		}
		else
		{
			//Since these are used items we only should order 1 of each type
			ubItemsOrdered = 1;
		}
	}
	else
	{
		// can't obtain this item from suppliers
		ubItemsOrdered = 0;
	}


	return(ubItemsOrdered);
}