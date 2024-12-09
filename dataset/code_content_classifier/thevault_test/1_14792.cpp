FOR_EACH_MERC_PLACEMENT(i)
						{ //Find locations of each member of the group, but don't place them yet.  If
							//one of the mercs can't be placed, then we won't place any, and tell the user
							//the problem.  If everything's okay, we will place them all.
							MERCPLACEMENT const& m = *i;
							if (m.pSoldier->ubGroupID == gubSelectedGroupID)
							{
								m.pSoldier->usStrategicInsertionData = SearchForClosestPrimaryMapEdgepoint(sGridNo, m.ubStrategicInsertionCode);
								if (m.pSoldier->usStrategicInsertionData == NOWHERE)
								{
									fInvalidArea = TRUE;
									break;
								}
							}
						}