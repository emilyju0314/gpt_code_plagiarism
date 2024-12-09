void ReleaseSoldiersAttacker( SOLDIERTYPE *pSoldier )
{
	INT32 cnt;
	UINT8 ubNumToFree;

	//if (gTacticalStatus.uiFlags & INCOMBAT)
	{
		// ATE: Removed...
		//if (pSoldier->attacker != NULL)
		{
			// JA2 Gold
			// set next-to-previous attacker, so long as this isn't a repeat attack
			if (pSoldier->previous_attacker != pSoldier->attacker)
			{
				pSoldier->next_to_previous_attacker = pSoldier->previous_attacker;
			}

			// get previous attacker id
			pSoldier->previous_attacker = pSoldier->attacker;

			// Copy BeingAttackedCount here....
			ubNumToFree = pSoldier->bBeingAttackedCount;
			// Zero it out BEFORE, as supression may increase it again...
			pSoldier->bBeingAttackedCount = 0;

			for ( cnt = 0; cnt < ubNumToFree; cnt++ )
			{
				SLOGD("Freeing up attacker of %d (attacker is %d)\n\
					releasesoldierattacker num to free is %d",
					pSoldier->ubID, SOLDIER2ID(pSoldier->attacker), ubNumToFree);
				ReduceAttackBusyCount(pSoldier->attacker, FALSE);
			}

			// ATE: Set to NOBODY if this person is NOT dead
			// otherise, we keep it so the kill can be awarded!
			if ( pSoldier->bLife != 0 && pSoldier->ubBodyType != QUEENMONSTER )
			{
				pSoldier->attacker = NULL;
			}
		}
	}
}