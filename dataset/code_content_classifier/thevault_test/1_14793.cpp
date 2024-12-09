FOR_EACH_MERC_PLACEMENT(i)
							{
								MERCPLACEMENT& m = *i;
								m.pSoldier->ubStrategicInsertionCode = INSERTION_CODE_GRIDNO;
								if (m.pSoldier->ubGroupID == gubSelectedGroupID)
								{
									PutDownMercPiece(m);
								}
							}