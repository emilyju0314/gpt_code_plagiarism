CFOR_EACH_SOLDIERINITNODE(curr)
		{
			if (!curr->pDetailedPlacement) continue;
			SOLDIERCREATE_STRUCT& dp = *curr->pDetailedPlacement;
			dp.ubScheduleID       = 0;
			dp.fUseGivenVehicle   = 0;
			dp.bUseGivenVehicleID = 0;
			dp.fHasKeys           = 0;
		}