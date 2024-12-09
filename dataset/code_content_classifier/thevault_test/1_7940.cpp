static int grid_can_moveto(UNIVERSE *u, ORGANISM *o, int x, int y)
{
	GRID_TYPE type;
	UNIVERSE_GRID ugrid;

	ASSERT( u != NULL );
	ASSERT( o != NULL );

	if( x < 0 || x >= u->width )
		return 0;

	if( y < 0 || y >= u->height )
		return 0;

	type = Grid_Get(u, x, y, &ugrid);

	if( type == GT_BLANK )
		return 1;

	if( type == GT_CELL && ugrid.u.cell->organism == o )
		return 1;

	return 0;
}