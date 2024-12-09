void InitVehicles(void)
{
	INT32 cnt;
	for( cnt = 0; cnt <  MAX_VEHICLES; cnt++ )
	{
		// create mvt groups
		GROUP* const g = CreateNewVehicleGroupDepartingFromSector(1, 1);
		g->fPersistant = TRUE;
		gubVehicleMovementGroups[cnt] = g->ubGroupID;
	}
}