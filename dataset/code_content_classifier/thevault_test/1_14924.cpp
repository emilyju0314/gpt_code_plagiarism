BOOLEAN ReevaluateEnemyStance( SOLDIERTYPE *pSoldier, UINT16 usAnimState )
{
	// make the chosen one not turn to face us
	if (OK_ENEMY_MERC(pSoldier) &&
		pSoldier != gTacticalStatus.the_chosen_one &&
		gAnimControl[usAnimState].ubEndHeight == ANIM_STAND &&
		!(pSoldier->uiStatusFlags & SOLDIER_UNDERAICONTROL))
	{
		if ( pSoldier->fTurningFromPronePosition == TURNING_FROM_PRONE_OFF )
		{
			// If we are a queen and see enemies, goto ready
			if ( pSoldier->ubBodyType == QUEENMONSTER )
			{
				if ( gAnimControl[ usAnimState ].uiFlags & ( ANIM_BREATH ) )
				{
					if ( pSoldier->bOppCnt > 0 )
					{
						EVENT_InitNewSoldierAnim( pSoldier, QUEEN_INTO_READY, 0 , TRUE );
						return( TRUE );
					}
				}
			}

			// ATE: Don't do this if we're not a merc.....
			if ( !IS_MERC_BODY_TYPE( pSoldier ) )
			{
				return( FALSE );
			}

			if ( gAnimControl[ usAnimState ].uiFlags & ( ANIM_MERCIDLE | ANIM_BREATH ) )
			{
				GridNo closest = NOWHERE;
				if (pSoldier->bOppCnt > 0)
				{
					// Pick a guy this buddy sees and turn towards them!
					INT16 sClosestDist = 10000;
					CFOR_EACH_IN_TEAM(opp, OUR_TEAM)
					{
						if (pSoldier->bOppList[opp->ubID] == SEEN_CURRENTLY)
						{
							const GridNo gridno = opp->sGridNo;
							const INT16 sDist   = PythSpacesAway(pSoldier->sGridNo, gridno);
							if (sDist < sClosestDist)
							{
								sClosestDist = sDist;
								closest      = gridno;
							}
						}
					}

					if (closest != NOWHERE)
					{
						// Change to fire ready animation
						pSoldier->fDontChargeReadyAPs = TRUE;
						return SoldierReadyWeapon(pSoldier, closest, FALSE);
					}
				}
			}
		}
	}
	return( FALSE );

}