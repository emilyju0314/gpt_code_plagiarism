FOR_EACH_IN_TEAM(pPatient, OUR_TEAM)
	{
		if (!pPatient->bInSector)
		{
			continue; // NEXT!!!
		}

		if (pPatient->bLife > 0 && pPatient->bBleeding && pPatient->ubServiceCount == 0)
		{
			if (pPatient->bLife < OKLIFE)
			{
				bPatientPriority = 3;
			}
			else if (pPatient->bLife < OKLIFE * 2)
			{
				bPatientPriority = 2;
			}
			else
			{
				bPatientPriority = 1;
			}

			if (bPatientPriority >= bBestPriority)
			{
				if ( !ClimbingNecessary( pSoldier, pPatient->sGridNo, pPatient->bLevel ) )
				{

					sPatientGridNo = pPatient->sGridNo;
					INT16 sAdjacentGridNo = FindAdjacentGridEx(pSoldier, sPatientGridNo, NULL, NULL, FALSE, FALSE);
					if ( sAdjacentGridNo == -1 && gAnimControl[ pPatient->usAnimState ].ubEndHeight == ANIM_PRONE )
					{
						// prone; could be the base tile is inaccessible but the rest isn't...
						for (UINT8 cnt2 = 0; cnt2 < NUM_WORLD_DIRECTIONS; ++cnt2)
						{
							sPatientGridNo = pPatient->sGridNo + DirectionInc( cnt2 );
							if (WhoIsThere2(sPatientGridNo, pPatient->bLevel) == pPatient)
							{
								// patient is also here, try this location
								sAdjacentGridNo = FindAdjacentGridEx(pSoldier, sPatientGridNo, NULL, NULL, FALSE, FALSE);
								if ( sAdjacentGridNo != -1 )
								{
									break;
								}
							}
						}
					}

					if (sAdjacentGridNo != -1)
					{
						if (sAdjacentGridNo == pSoldier->sGridNo)
						{
							sPathCost = 1;
						}
						else
						{
							sPathCost = PlotPath(pSoldier, sAdjacentGridNo, FALSE, FALSE, RUNNING, 0);
						}

						if ( sPathCost != 0 )
						{
							// we can get there... can anyone else?
							SOLDIERTYPE* const pOtherMedic = pPatient->auto_bandaging_medic;
							if (pOtherMedic != NULL && pOtherMedic != pSoldier)
							{
								// only switch to this patient if our distance is closer than
								// the other medic's
								const INT16 sOtherAdjacentGridNo = FindAdjacentGridEx(pOtherMedic, sPatientGridNo, NULL, NULL, FALSE, FALSE);
								if (sOtherAdjacentGridNo != -1)
								{

									if (sOtherAdjacentGridNo == pOtherMedic->sGridNo)
									{
										sOtherMedicPathCost = 1;
									}
									else
									{
										sOtherMedicPathCost = PlotPath(pOtherMedic, sOtherAdjacentGridNo, FALSE, FALSE, RUNNING, 0);
									}

									if (sPathCost >= sOtherMedicPathCost)
									{
										// this patient is best served by the merc moving to them now
										continue;
									}
								}
							}

							if (bPatientPriority == bBestPriority)
							{
								// compare path distances
								if ( sPathCost > sShortestPath )
								{
									continue;
								}
							}


							sShortestPath = sPathCost;
							pBestPatient = pPatient;
							sBestPatientGridNo = sPatientGridNo;
							bBestPriority = bPatientPriority;
							sBestAdjGridNo = sAdjacentGridNo;

						}
					}

				}
				else
				{
					sClimbGridNo = NOWHERE;
					// see if guy on another building etc and we need to climb somewhere
					sPathCost = EstimatePathCostToLocation( pSoldier, pPatient->sGridNo, pPatient->bLevel, FALSE, &fClimbingNecessary, &sClimbGridNo );
					// if we can get there
					if ( sPathCost != 0 && fClimbingNecessary && sPathCost < sShortestClimbPath )
					{
						sBestClimbGridNo = sClimbGridNo;
						sShortestClimbPath = sPathCost;
					}

				}

			}

		}
	}