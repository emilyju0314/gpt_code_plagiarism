static void SelectDealersInventoryRegionCallBack(MOUSE_REGION* pRegion, INT32 iReason)
{
	if (iReason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		UINT8 ubSelectedInvSlot = (UINT8)MSYS_GetRegionUserData( pRegion, 0 );
		INT8  ubLocation;

		if( gpTempDealersInventory == NULL )
			return;

		ubSelectedInvSlot += gSelectArmsDealerInfo.ubFirstItemIndexOnPage;

		//if the selected slot is above any inventory we have, return
		if( ubSelectedInvSlot >= gSelectArmsDealerInfo.uiNumDistinctInventoryItems )
			return;

		//if there are any items still there
		if( gpTempDealersInventory[ ubSelectedInvSlot ].ItemObject.ubNumberOfObjects > 0 )
		{
			//If the item type has not already been placed
			if( !( gpTempDealersInventory[ ubSelectedInvSlot ].uiFlags & ARMS_INV_ITEM_SELECTED ) )
			{
				//if the dealer repairs
				if (DoesDealerDoRepairs(gbSelectedArmsDealerID))
				{
					// ignore left clicks on items under repair.  Fully repaired items are moved out to player's slots automatically
				}
				else // not a repairman
				{
					ubLocation = AddItemToArmsDealerOfferArea( &gpTempDealersInventory[ ubSelectedInvSlot ], ubSelectedInvSlot );

					//if the item was added to the Dealer Offer Area correctly
					if( ubLocation != -1 )
					{
						//Set the flag indicating the item has been selected
						gpTempDealersInventory[ ubSelectedInvSlot ].uiFlags |= ARMS_INV_ITEM_SELECTED;

						//Specify the location the items went to
						gpTempDealersInventory[ ubSelectedInvSlot ].ubLocationOfObject = ARMS_DEALER_OFFER_AREA;
						gpTempDealersInventory[ ubSelectedInvSlot ].bSlotIdInOtherLocation = ubLocation;

						//if the shift key is being pressed, remove them all
						if (_KeyDown(SHIFT))
						{
							gpTempDealersInventory[ ubSelectedInvSlot ].ItemObject.ubNumberOfObjects = 0;
						}
						else
						{
							gpTempDealersInventory[ ubSelectedInvSlot ].ItemObject.ubNumberOfObjects --;
						}

						gubSkiDirtyLevel = SKI_DIRTY_LEVEL2;
					}
				}
			}
			else // some of this item are already in dealer's offer area
			{
				UINT8 ubNumToMove;

				//if the shift key is being pressed, remove them all
				if (_KeyDown(SHIFT))
				{
					ubNumToMove = gpTempDealersInventory[ ubSelectedInvSlot ].ItemObject.ubNumberOfObjects;
				}
				else
				{
					ubNumToMove = 1;
				}

				//Reduce the number in dealer's inventory
				gpTempDealersInventory[ ubSelectedInvSlot ].ItemObject.ubNumberOfObjects -= ubNumToMove;
				//Increase the number in dealer's offer area
				ArmsDealerOfferArea[ gpTempDealersInventory[ ubSelectedInvSlot ].bSlotIdInOtherLocation ].ItemObject.ubNumberOfObjects += ubNumToMove;

				gubSkiDirtyLevel = SKI_DIRTY_LEVEL2;
			}
		}
	}

	else if (iReason & MSYS_CALLBACK_REASON_RBUTTON_UP)
	{
		UINT8 ubSelectedInvSlot = (UINT8)MSYS_GetRegionUserData( pRegion, 0 );

		if( gpTempDealersInventory == NULL )
			return;

		ubSelectedInvSlot += gSelectArmsDealerInfo.ubFirstItemIndexOnPage;

		//if the selected slot is above any inventory we have, return
		if( ubSelectedInvSlot >= gSelectArmsDealerInfo.uiNumDistinctInventoryItems )
			return;

		//DEF:
		//bring up the item description box
		if ( !InItemDescriptionBox( ) )
		{
			InitShopKeeperItemDescBox( &gpTempDealersInventory[ ubSelectedInvSlot ].ItemObject, ubSelectedInvSlot, ARMS_DEALER_INVENTORY );
		}
		else
		{
			DeleteItemDescriptionBox( );
		}



		/*
		//if the item has been seleceted
		if( gpTempDealersInventory[ ubSelectedInvSlot ].uiFlags & ARMS_INV_ITEM_SELECTED )
		{
			//Check to see it there is more then 1 item in the location
			INVENTORY_IN_SLOT* const a = &ArmsDealerOfferArea[gpTempDealersInventory[ubSelectedInvSlot].bSlotIdInOtherLocation];
			if (a->ItemObject.ubNumberOfObjects > 0)
			{
				//Increase the number in the dealer inventory
				gpTempDealersInventory[ ubSelectedInvSlot ].ItemObject.ubNumberOfObjects ++;

				//Decrease the number in the dealer offer area
				a->ItemObject.ubNumberOfObjects--;

				//if there is nothing left in the arms dealer offer area
				if (a->ItemObject.ubNumberOfObjects == 0)
				{
					RemoveItemFromArmsDealerOfferArea( gpTempDealersInventory[ ubSelectedInvSlot ].bSlotIdInOtherLocation, FALSE );
				}

				//redraw the screen
				gubSkiDirtyLevel = SKI_DIRTY_LEVEL2;
			}
		}*/
	}
	else if (iReason & MSYS_CALLBACK_REASON_WHEEL_UP)
	{
		ShopInventoryPageUp();
	}
	else if (iReason & MSYS_CALLBACK_REASON_WHEEL_DOWN)
	{
		ShopInventoryPageDown();
	}
}