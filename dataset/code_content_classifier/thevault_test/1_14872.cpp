GROUP* CreateNewPlayerGroupDepartingFromSector(UINT8 const ubSectorX, UINT8 const ubSectorY)
{
	AssertMsg( ubSectorX >= 1 && ubSectorX <= 16, String( "CreateNewPlayerGroup with out of range sectorX value of %d", ubSectorX ) );
	AssertMsg( ubSectorY >= 1 && ubSectorY <= 16, String( "CreateNewPlayerGroup with out of range sectorY value of %d", ubSectorY ) );
	GROUP* const pNew = new GROUP{};
	pNew->pPlayerList = NULL;
	pNew->pWaypoints = NULL;
	pNew->ubSectorX = pNew->ubNextX = ubSectorX;
	pNew->ubSectorY = pNew->ubNextY = ubSectorY;
	pNew->ubOriginalSector = (UINT8)SECTOR( ubSectorX, ubSectorY );
	pNew->fPlayer = TRUE;
	pNew->ubMoveType = ONE_WAY;
	pNew->ubNextWaypointID = 0;
	pNew->ubTransportationMask = FOOT;
	pNew->fVehicle = FALSE;
	pNew->ubCreatedSectorID = pNew->ubOriginalSector;
	pNew->ubSectorIDOfLastReassignment = 255;

	AddGroupToList(pNew);
	return pNew;
}