static void HandleCompletionOfTownTrainingByGroupWithTrainer(SOLDIERTYPE* pTrainer)
{

	INT16 sSectorX = 0, sSectorY = 0;
	INT8 bSectorZ = 0;

	// get the sector values
	sSectorX = pTrainer->sSectorX;
	sSectorY = pTrainer->sSectorY;
	bSectorZ = pTrainer->bSectorZ;

	CFOR_EACH_IN_CHAR_LIST(c)
	{
		SOLDIERTYPE* const pSoldier = c->merc;
		if( ( pSoldier->bAssignment == TRAIN_TOWN ) && ( pSoldier->sSectorX == sSectorX )&&( pSoldier->sSectorY == sSectorY )&&( pSoldier->bSectorZ == bSectorZ ) )
		{
			// done assignment
			AssignmentDone( pSoldier, FALSE, FALSE );
		}
	}
}