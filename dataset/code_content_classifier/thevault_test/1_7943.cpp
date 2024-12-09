CELL *Cell_Neighbor(CELL *cell, int xoffset, int yoffset)
{
	UNIVERSE_GRID grid;
	UNIVERSE *u;
	int x, y;
	GRID_TYPE type;

	ASSERT( cell != NULL );

	u = cell->organism->universe;

	x = cell->x + xoffset;
	y = cell->y + yoffset;

	if( x < 0 || x >= u->width )
		return NULL;

	if( y < 0 || y >= u->height )
		return NULL;

	type = Grid_Get(u, x, y, &grid);
	if( type == GT_CELL ) {
		if( grid.u.cell->organism == cell->organism ) {
			return grid.u.cell;
		}
	}

	return NULL;
}