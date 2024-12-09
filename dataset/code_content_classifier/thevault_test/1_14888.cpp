static void SetGroupNextSectorValue(INT16 const x, INT16 const y, GROUP& g)
{
	RemoveGroupWaypoints(g);
	// Set sector x and y to passed values
	g.ubNextX         = x;
	g.ubNextY         = y;
	g.fBetweenSectors = FALSE;
	// Set next sectors same as current
	g.ubOriginalSector = SECTOR(g.ubSectorX, g.ubSectorY);
}