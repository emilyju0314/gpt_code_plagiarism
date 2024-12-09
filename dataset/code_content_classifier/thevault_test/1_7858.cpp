static void color_all_cells(CELL *cell, int *color)
{
	CELL *north, *south, *east, *west;

	ASSERT( cell != NULL );
	ASSERT( color != NULL );

	north = Cell_Neighbor(cell, 0, -1);
	south = Cell_Neighbor(cell, 0, 1);
	east = Cell_Neighbor(cell, 1, 0);
	west = Cell_Neighbor(cell, -1, 0);

	if( COLOR_IT(north) ) {
		(*color)++;
		color_cells(north, *color);
	}

	if( COLOR_IT(south) ) {
		(*color)++;
		color_cells(south, *color);
	}

	if( COLOR_IT(east) ) {
		(*color)++;
		color_cells(east, *color);
	}

	if( COLOR_IT(west) ) {
		(*color)++;
		color_cells(west, *color);
	}
}