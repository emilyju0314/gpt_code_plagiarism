void SetFirstLastPagesForNew( UINT32 uiClassMask )
{
	UINT16 i;
	INT16	sFirst = -1;
	INT16	sLast = -1;
	UINT8	ubNumItems=0;

	gubCurPage = 0;

	//First loop through to get the first and last index indexs
	for(i=0; i<MAXITEMS; i++)
	{
		//If we have some of the inventory on hand
		if( LaptopSaveInfo.BobbyRayInventory[ i ].ubQtyOnHand != 0 )
		{
			if( GCM->getItem(LaptopSaveInfo.BobbyRayInventory[ i ].usItemIndex)->getItemClass() & uiClassMask )
			{
				ubNumItems++;

				if( sFirst == -1 )
					sFirst = i;
				sLast = i;
			}
		}
	}

	if( ubNumItems == 0 )
	{
		gusFirstItemIndex = BOBBYR_NO_ITEMS;
		gusLastItemIndex = BOBBYR_NO_ITEMS;
		gubNumPages = 0;
		return;
	}

	gusFirstItemIndex = (UINT16)sFirst;
	gusLastItemIndex = (UINT16)sLast;
	gubNumPages = (UINT8)( ubNumItems / (FLOAT)BOBBYR_NUM_WEAPONS_ON_PAGE );
	if( (ubNumItems % BOBBYR_NUM_WEAPONS_ON_PAGE ) != 0 )
		gubNumPages += 1;
}