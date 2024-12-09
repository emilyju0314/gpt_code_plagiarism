int CSpawnPointGenerator::FillInDir( SpawnGridLoc *refLoc, int dir )
{
	StepThroughDir(refLoc, dir);
	int numCreated = 0;

	// create a new spot in each open space
	do {
		CBaseEntity *newSpot = CreateEntityByName( m_pszPointName );
		newSpot->SetAbsAngles(m_angles);
		newSpot->SetAbsOrigin(refLoc->vecOrigin);
		refLoc->iStatus = OCCUPIED;
		m_iSpawnsCreated++;
		numCreated++;
		UpdateTryLists(refLoc);
		refLoc = CheckStatusInDir(refLoc, dir);
	} while (refLoc && (refLoc->iStatus == OPEN));

	return numCreated;
}