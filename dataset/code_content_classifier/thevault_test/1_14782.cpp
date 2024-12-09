static void SelectPlayersOfferSlotsRegionCallBack(MOUSE_REGION* pRegion, INT32 iReason)
{
	UINT8 ubSelectedInvSlot = (UINT8)MSYS_GetRegionUserData( pRegion, 0 );
	INVENTORY_IN_SLOT* const o = &PlayersOfferArea[ubSelectedInvSlot];
	INT8 bAddedToSlotID = -1;

	if (iReason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		//if the cursor has no item in it
		if( gMoveingItem.sItemIndex == 0 )
		{
			//if there is nothing here, return
			if (!o->fActive)
				return;

			// pick it up into the cursor
			BeginSkiItemPointer( PLAYERS_OFFER_AREA, ubSelectedInvSlot, FALSE );
		}
		else	// we have something in the cursor
		{
			//Drop the item into the current slot
			//if there is something already there
			if (o->fActive)
			{
				//swap what is in the cursor with what is in the player offer slot

				// if the slot is overloaded (holds more objects than we have room for valid statuses of)
				if (o->ItemObject.ubNumberOfObjects > MAX_OBJECTS_PER_SLOT)
				{
					// then ignore the click - we can't do the swap, or anything very useful, because we can't allow overloaded
					// items into the player's cursor - if he put them into a merc's inventory, the extra statuses are missing!
					// At best, we could do some sort of message here.
					return;
				}

				IfMercOwnedCopyItemToMercInv( &gMoveingItem );

				const INVENTORY_IN_SLOT TempSlot = *o;
				*o = gMoveingItem;
				gMoveingItem = TempSlot;

				IfMercOwnedRemoveItemFromMercInv( &gMoveingItem );

				// Change mouse cursor
				gpItemPointer = &gMoveingItem.ItemObject;
				SetSkiCursor( EXTERN_CURSOR );

				//if the item we are adding is money
				if (GCM->getItem(o->sItemIndex)->getItemClass() == IC_MONEY)
				{
					//Since money is always evaluated
					o->uiFlags     |= ARMS_INV_PLAYERS_ITEM_HAS_VALUE;
					o->uiItemPrice  = o->ItemObject.bMoneyStatus;
				}
			}
			else	// slot is empty
			{
				// if the item has already been evaluated, or has just been purchased
				if ( ( gMoveingItem.uiFlags & ARMS_INV_PLAYERS_ITEM_HAS_BEEN_EVALUATED ) ||
					( gMoveingItem.uiFlags & ARMS_INV_JUST_PURCHASED ) )
				{
					//place the item that is in the player's hand into this player offer area slot
					bAddedToSlotID = AddInventoryToSkiLocation( &gMoveingItem, ubSelectedInvSlot, PLAYERS_OFFER_AREA );
					Assert ( bAddedToSlotID != -1 );
				}
				else
				{
					// this splits complex items for repairs.  Also puts things into the first free POA slot
					OfferObjectToDealer( &gMoveingItem.ItemObject, gMoveingItem.ubIdOfMercWhoOwnsTheItem, gMoveingItem.bSlotIdInOtherLocation );
				}

				//Reset the cursor
				SetSkiCursor( CURSOR_NORMAL );
			}

			//Dirty the interface
			gubSkiDirtyLevel = SKI_DIRTY_LEVEL2;
		}
	}
	else if(iReason & MSYS_CALLBACK_REASON_RBUTTON_UP ) //MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		//if the box is active
		if (o->fActive)
		{
			RemoveItemFromPlayersOfferArea( ubSelectedInvSlot );
			/*
			item description
			else
			{
				if ( !InItemDescriptionBox( ) )
				{
					InitItemDescriptionBox(gpSMCurrentMerc, o->bSlotIdInOtherLocation, 214, 1 + INV_INTERFACE_START_Y, 0);
				}
				else
				{
					DeleteItemDescriptionBox( );
				}
			}*/
		}
		gubSkiDirtyLevel = SKI_DIRTY_LEVEL2;
	}
}