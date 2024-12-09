FOR_EACH_IN_TEAM(pSoldier, OUR_TEAM)
			{
				SoldierSP soldier = GetSoldier(pSoldier);

				if (OkControllableMerc(pSoldier) && pSoldier->bAssignment == CurrentSquad() && !pSoldier->fMercAsleep)
				{
					// If we can't be controlled, returninvalid...
					if ( pSoldier->uiStatusFlags & SOLDIER_ROBOT )
					{
						if ( !CanRobotBeControlled( pSoldier ) )
						{
							continue;
						}
					}

					AdjustNoAPToFinishMove( pSoldier, FALSE );

					fOldFastMove = pSoldier->fUIMovementFast;

					if ( fAllMove == 2 )
					{
						pSoldier->fUIMovementFast = TRUE;
						pSoldier->usUIMovementMode = RUNNING;
					}
					else
					{
						pSoldier->fUIMovementFast = FALSE;
						pSoldier->usUIMovementMode =  GetMoveStateBasedOnStance( pSoldier, gAnimControl[ pSoldier->usAnimState ].ubEndHeight );
					}

					soldier->removePendingAction();

					//if ( !( gTacticalStatus.uiFlags & INCOMBAT ) && ( gAnimControl[ pSoldier->usAnimState ].uiFlags & ANIM_MOVING ) )
					//{
					//	pSoldier->sRTPendingMovementGridNo = usMapPos;
					//	pSoldier->usRTPendingMovementAnim  = pSoldier->usUIMovementMode;
					//}
					//else
					if ( EVENT_InternalGetNewSoldierPath( pSoldier, usMapPos, pSoldier->usUIMovementMode, TRUE, FALSE ) )
					{
						InternalDoMercBattleSound( pSoldier, BATTLE_SOUND_OK1, BATTLE_SND_LOWER_VOLUME );
					}
					else
					{
						ScreenMsg( FONT_MCOLOR_LTYELLOW, MSG_INTERFACE, st_format_printf(TacticalStr[ NO_PATH_FOR_MERC ], pSoldier->name) );
					}

					pSoldier->fUIMovementFast = fOldFastMove;

				}
			}