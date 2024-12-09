static FLOAT CalculateObjectTrajectory(INT16 sTargetZ, const OBJECTTYPE* pItem, vector_3* vPosition, vector_3* vForce, INT16* psFinalGridNo)
{
	FLOAT dDiffX, dDiffY;
	INT16 sGridNo;

	if ( psFinalGridNo )
	{
		(*psFinalGridNo) = NOWHERE;
	}

	REAL_OBJECT* const pObject = CreatePhysicalObject(pItem, -1, vPosition->x, vPosition->y, vPosition->z, vForce->x, vForce->y, vForce->z, NULL, NO_THROW_ACTION, 0);

	// Set some special values...
	pObject->fTestObject = TEST_OBJECT_NO_COLLISIONS;
	pObject->TestZTarget = sTargetZ;
	pObject->fTestPositionNotSet = TRUE;
	pObject->fVisible = FALSE;

	// Alrighty, move this beast until it dies....
	while( pObject->fAlive )
	{
		SimulateObject( pObject, (float)DELTA_T );
	}

	// Calculate gridno from last position
	sGridNo = MAPROWCOLTOPOS( ( (INT16)pObject->Position.y / CELL_Y_SIZE ), ( (INT16)pObject->Position.x / CELL_X_SIZE ) );

	PhysicsDeleteObject( pObject );

	// get new x, y, z values
	dDiffX = ( pObject->TestTargetPosition.x - vPosition->x );
	dDiffY = ( pObject->TestTargetPosition.y - vPosition->y );

	if ( psFinalGridNo )
	{
		(*psFinalGridNo) = sGridNo;
	}

	return( (FLOAT)sqrt( ( dDiffX * dDiffX ) + ( dDiffY * dDiffY ) ) );

}