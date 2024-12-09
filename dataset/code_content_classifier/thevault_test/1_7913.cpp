static void write_spores(FILE *fp, UNIVERSE *u)
{
	int x, y;
	GRID_TYPE type;
	UNIVERSE_GRID ugrid;

	ASSERT( fp != NULL );
	ASSERT( u != NULL );

	for(x=0; x < u->width; x++) {
		for(y=0; y < u->height; y++) {
			type = Grid_Get(u, x, y, &ugrid);

			if( type == GT_SPORE ) {
				write_spore(fp, x, y, ugrid.u.spore);
			}
		}
	}
}