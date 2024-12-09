GROUP* CreateNewEnemyGroupDepartingFromSector( UINT32 uiSector, UINT8 ubNumAdmins, UINT8 ubNumTroops, UINT8 ubNumElites )
{
	AssertMsg( uiSector <= 255, String( "CreateNewEnemyGroup with out of range value of %d", uiSector ) );
	GROUP* const pNew = new GROUP{};
	pNew->pEnemyGroup = new ENEMYGROUP{};
	pNew->pWaypoints = NULL;
	pNew->ubSectorX = (UINT8)SECTORX( uiSector );
	pNew->ubSectorY = (UINT8)SECTORY( uiSector );
	pNew->ubOriginalSector = (UINT8)uiSector;
	pNew->fPlayer = FALSE;
	pNew->ubMoveType = CIRCULAR;
	pNew->ubNextWaypointID = 0;
	pNew->pEnemyGroup->ubNumAdmins = ubNumAdmins;
	pNew->pEnemyGroup->ubNumTroops = ubNumTroops;
	pNew->pEnemyGroup->ubNumElites = ubNumElites;
	pNew->ubGroupSize = (UINT8)(ubNumTroops + ubNumElites);
	pNew->ubTransportationMask = FOOT;
	pNew->fVehicle = FALSE;
	pNew->ubCreatedSectorID = pNew->ubOriginalSector;
	pNew->ubSectorIDOfLastReassignment = 255;

	AddGroupToList(pNew);
	return pNew;
}