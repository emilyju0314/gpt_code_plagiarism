void CSpawnPointGenerator::UpdateTryLists( SpawnGridLoc *refLoc )
{
	int x = refLoc->xIndex;
	int y = refLoc->yIndex;
		
	if ( (x < iMaxX) && (GridLoc(x+1,y)->iStatus < BLOCKED) )
		m_arrCanLeft.AddToTail(refLoc);
	if ( (x > iCurMinX) && (GridLoc(x-1,y)->iStatus < BLOCKED) )
		m_arrCanRight.AddToTail(refLoc);
	if ( (y > iCurMinY) && (GridLoc(x,y-1)->iStatus < BLOCKED) )
		m_arrCanFront.AddToTail(refLoc);
}