bool Soldier::handlePendingAction(bool inCombat)
{
	if (mSoldier->ubPendingAction == MERC_PICKUPITEM)
	{
		const INT16 sGridNo = mSoldier->sPendingActionData2;
		if (sGridNo == mSoldier->sGridNo)
		{
			// OK, now, if in realtime
			if (!inCombat)
			{
				// If the two gridnos are not the same, check to see if we can
				// now go into it
				if (sGridNo != (INT16)mSoldier->uiPendingActionData4)
				{
					if (NewOKDestination(mSoldier, (INT16)mSoldier->uiPendingActionData4, TRUE, mSoldier->bLevel))
					{
						// GOTO NEW TILE!
						SoldierPickupItem(mSoldier, mSoldier->uiPendingActionData1, (INT16)mSoldier->uiPendingActionData4, mSoldier->bPendingActionData3);
						return true;
					}
				}
			}

			PickPickupAnimation(mSoldier, mSoldier->uiPendingActionData1, (INT16)mSoldier->uiPendingActionData4, mSoldier->bPendingActionData3);
		}
		else
		{
			SoldierGotoStationaryStance(mSoldier);
		}
	}
	else if (mSoldier->ubPendingAction == MERC_PUNCH)
	{
		// for the benefit of the AI
		mSoldier->bAction = AI_ACTION_KNIFE_STAB;

		EVENT_SoldierBeginPunchAttack(mSoldier, mSoldier->sPendingActionData2, mSoldier->bPendingActionData3);
		removePendingAction();
	}
	else if (mSoldier->ubPendingAction == MERC_TALK)
	{
		PlayerSoldierStartTalking(mSoldier, (UINT8)mSoldier->uiPendingActionData1, TRUE);
		removePendingAction();
	}
	else if (mSoldier->ubPendingAction == MERC_DROPBOMB)
	{
		EVENT_SoldierBeginDropBomb(mSoldier);
		removePendingAction();
	}
	else if (mSoldier->ubPendingAction == MERC_STEAL)
	{
		//mSoldier->bDesiredDirection = mSoldier->bPendingActionData3;
		EVENT_SetSoldierDesiredDirection(mSoldier, mSoldier->bPendingActionData3);

		EVENT_InitNewSoldierAnim(mSoldier, STEAL_ITEM, 0, FALSE);
		removePendingAction();
	}
	else if (mSoldier->ubPendingAction == MERC_KNIFEATTACK)
	{
		// for the benefit of the AI
		mSoldier->bAction = AI_ACTION_KNIFE_STAB;

		EVENT_SoldierBeginBladeAttack(mSoldier, mSoldier->sPendingActionData2, mSoldier->bPendingActionData3);
		removePendingAction();
	}
	else if (mSoldier->ubPendingAction == MERC_GIVEAID)
	{
		EVENT_SoldierBeginFirstAid(mSoldier, mSoldier->sPendingActionData2, mSoldier->bPendingActionData3);
		removePendingAction();
	}
	else if (mSoldier->ubPendingAction == MERC_REPAIR)
	{
		EVENT_SoldierBeginRepair(*mSoldier, mSoldier->sPendingActionData2, mSoldier->bPendingActionData3);
		removePendingAction();
	}
	else if (mSoldier->ubPendingAction == MERC_FUEL_VEHICLE)
	{
		EVENT_SoldierBeginRefuel(mSoldier, mSoldier->sPendingActionData2, mSoldier->bPendingActionData3);
		removePendingAction();
	}
	else if (mSoldier->ubPendingAction == MERC_RELOADROBOT)
	{
		EVENT_SoldierBeginReloadRobot(mSoldier, mSoldier->sPendingActionData2, mSoldier->bPendingActionData3, (INT8)mSoldier->uiPendingActionData1);
		removePendingAction();
	}
	else if (mSoldier->ubPendingAction == MERC_TAKEBLOOD)
	{
		EVENT_SoldierBeginTakeBlood( mSoldier, mSoldier->sPendingActionData2, mSoldier->bPendingActionData3 );
		removePendingAction();
	}
	else if (mSoldier->ubPendingAction == MERC_ATTACH_CAN)
	{
		EVENT_SoldierBeginAttachCan(mSoldier, mSoldier->sPendingActionData2, mSoldier->bPendingActionData3);
		removePendingAction();
	}
	else if (mSoldier->ubPendingAction == MERC_ENTER_VEHICLE)
	{
		EVENT_SoldierEnterVehicle(*mSoldier, mSoldier->sPendingActionData2);
		removePendingAction();
		return true;
	}
	else if (mSoldier->ubPendingAction == MERC_CUTFFENCE)
	{
		EVENT_SoldierBeginCutFence(mSoldier, mSoldier->sPendingActionData2, mSoldier->bPendingActionData3);
		removePendingAction();
	}
	else if (mSoldier->ubPendingAction == MERC_GIVEITEM)
	{
		EVENT_SoldierBeginGiveItem(mSoldier);
		removePendingAction();
	}
	return false;
}