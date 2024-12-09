static void color_cells(CELL *cell, int color)
{
	CELL *north, *south, *east, *west;

	ASSERT( cell != NULL );

	north = Cell_Neighbor(cell, 0, -1);
	south = Cell_Neighbor(cell, 0, 1);
	east = Cell_Neighbor(cell, 1, 0);
	west = Cell_Neighbor(cell, -1, 0);

	cell->color = (char)color;

	if( COLOR_IT(north) )
		color_cells(north, color);

	if( COLOR_IT(south) )
		color_cells(south, color);

	if( COLOR_IT(east) )
		color_cells(east, color);

	if( COLOR_IT(west) )
		color_cells(west, color);
}