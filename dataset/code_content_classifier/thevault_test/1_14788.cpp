static void SelectArmsDealersDropItemToGroundRegionCallBack(MOUSE_REGION* pRegion, INT32 iReason)
{
	if (iReason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		SOLDIERTYPE *pDropSoldier;

		// use the current merc, unless he's ineligible, then use the selected merc instead.
		if( !gfSMDisableForItems )
		{
			pDropSoldier = gpSMCurrentMerc;
		}
		else
		{
			pDropSoldier = GetSelectedMan();
		}

		//if we don't have an item, pick one up
		if( gMoveingItem.sItemIndex != 0 )
		{
			//add the item to the ground
			ShopkeeperAddItemToPool(pDropSoldier->sGridNo, &gMoveingItem.ItemObject, pDropSoldier->bLevel);

			//Reset the cursor
			SetSkiCursor( CURSOR_NORMAL );

			//refresh the screen
			gubSkiDirtyLevel = SKI_DIRTY_LEVEL2;
		}
	}
}