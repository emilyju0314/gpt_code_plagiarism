static UINT32 UndergroundTacticalTraversalTime(INT8 const exit_direction)
{ /* We are attempting to traverse in an underground environment. We need to use
	 * a complete different method.  When underground, all sectors are instantly
	 * adjacent. */
	GridNo gridno;
	switch (exit_direction)
	{
		case NORTH_STRATEGIC_MOVE: gridno = gMapInformation.sNorthGridNo; break;
		case EAST_STRATEGIC_MOVE:  gridno = gMapInformation.sEastGridNo;  break;
		case SOUTH_STRATEGIC_MOVE: gridno = gMapInformation.sSouthGridNo; break;
		case WEST_STRATEGIC_MOVE:  gridno = gMapInformation.sWestGridNo;  break;
		default: throw std::logic_error("invalid exit direction");
	}
	return gridno != -1 ? 0 : TRAVERSE_TIME_IMPOSSIBLE;
}