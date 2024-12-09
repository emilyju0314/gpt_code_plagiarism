static void MilitiaTrainingRejected(void)
{
	if( gfYesNoPromptIsForContinue )
	{
		// take all mercs in that sector off militia training
		ResetAssignmentOfMercsThatWereTrainingMilitiaInThisSector( pMilitiaTrainerSoldier->sSectorX, pMilitiaTrainerSoldier->sSectorY );
	}
	else
	{
		// take all mercs in unpaid sectors EVERYWHERE off militia training
		ResetAssignmentsForMercsTrainingUnpaidSectorsInSelectedList();
	}

	// this completes the training prompt sequence
	pMilitiaTrainerSoldier = NULL;
}