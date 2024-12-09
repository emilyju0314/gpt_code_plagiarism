void CSpawnPointGenerator::BoundsForDir( int dir, int *xmod, int *ymod)
{
	switch(dir)
	{
		case DIR_LEFT:
			{
			*xmod = iMaxX;
			break;
			}
		case DIR_RIGHT:
			{
			*xmod = iCurMinX;
			break;
			}
		case DIR_FRONT:
			{
			*ymod = iCurMinY;
			break;
			}
		// defaults to back dir
		default:
			*ymod = iMaxY;
	}
}