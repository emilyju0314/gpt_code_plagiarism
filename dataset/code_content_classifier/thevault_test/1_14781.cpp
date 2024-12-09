static void SelectDealersOfferSlotsRegionCallBack(MOUSE_REGION* pRegion, INT32 iReason)
{
	UINT8	ubSelectedInvSlot = (UINT8)MSYS_GetRegionUserData( pRegion, 0 );
	INVENTORY_IN_SLOT* const a = &ArmsDealerOfferArea[ubSelectedInvSlot];

	if (iReason & MSYS_CALLBACK_REASON_RBUTTON_UP)
	{
		//if there is something here
		if (a->fActive)
		{
			//if the dealer repairs
			if (DoesDealerDoRepairs(gbSelectedArmsDealerID))
			{
				// return item to player
				RemoveRepairItemFromDealersOfferArea( ubSelectedInvSlot );
			}
			else
			{
				//bring up the item description box
				if ( !InItemDescriptionBox( ) )
				{
					InitShopKeeperItemDescBox(&a->ItemObject, ubSelectedInvSlot, ARMS_DEALER_OFFER_AREA);
				}
				else
				{
					DeleteItemDescriptionBox( );
				}
			}
		}
	}
	else if( iReason & MSYS_CALLBACK_REASON_LBUTTON_UP ) //MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		/*
		//if the current merc is disabled for whatever reason
		if( gfSMDisableForItems )
			// the
			return;*/
		//if there is something here
		if (a->fActive)
		{
			//if this is a repair dealer
			if (DoesDealerDoRepairs(gbSelectedArmsDealerID))
			{
				//if we don't have an item, pick one up
				if( gMoveingItem.sItemIndex == 0 )
				{
					//if the dealer is a repair dealer, allow the player to pick up the item
					if (DoesDealerDoRepairs(gbSelectedArmsDealerID))
					{
						BeginSkiItemPointer( ARMS_DEALER_OFFER_AREA, ubSelectedInvSlot, FALSE );
					}
				}
				else
				{
					//swap what is in the cursor with what is in the player offer slot

					// if the slot is overloaded (holds more objects than we have room for valid statuses of)
					if (a->ItemObject.ubNumberOfObjects > MAX_OBJECTS_PER_SLOT)
					{
						// then ignore the click - we can't do the swap, or anything very useful, because we can't allow overloaded
						// items into the player's cursor - if he put them into a merc's inventory, the extra statuses are missing!
						// At best, we could do some sort of message here.
						return;
					}

					IfMercOwnedCopyItemToMercInv( &gMoveingItem );

					const INVENTORY_IN_SLOT TempSlot = *a;
					*a = gMoveingItem;
					gMoveingItem = TempSlot;

					IfMercOwnedRemoveItemFromMercInv( &gMoveingItem );

					// Change mouse cursor
					gpItemPointer = &gMoveingItem.ItemObject;
					SetSkiCursor( EXTERN_CURSOR );

					gubSkiDirtyLevel = SKI_DIRTY_LEVEL2;
				}
			}
			else //non-repairman
			{
				//if the shift key is being pressed, remove them all
				if (_KeyDown(SHIFT) || a->ItemObject.ubNumberOfObjects == 1)
				{
					RemoveItemFromArmsDealerOfferArea(ubSelectedInvSlot, TRUE);//a->bSlotIdInOtherLocation
				}
				else	// multiple items there, SHIFT isn't being pressed
				{
					// remove only one at a time
					a->ItemObject.ubNumberOfObjects--;
					gpTempDealersInventory[a->bSlotIdInOtherLocation].ItemObject.ubNumberOfObjects++;
				}

				gubSkiDirtyLevel = SKI_DIRTY_LEVEL2;
			}
		}
		else // empty slot
		{
			//if the cursor has something in it
			if( gMoveingItem.sItemIndex > 0 )
			{
				// we'd better talking to a repairman, cursor is locked out of this area while full for non-repairmen!
				Assert(DoesDealerDoRepairs(gbSelectedArmsDealerID));

				//Drop the item into the current slot
				AddInventoryToSkiLocation( &gMoveingItem, ubSelectedInvSlot, ARMS_DEALER_OFFER_AREA );

				//Reset the cursor
				SetSkiCursor( CURSOR_NORMAL );

				//refresh the screen
				gubSkiDirtyLevel = SKI_DIRTY_LEVEL2;
			}
		}
	}
}