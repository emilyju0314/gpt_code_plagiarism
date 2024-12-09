static void look_along_line(UNIVERSE *u, CELL *c, int xoffset, int yoffset, int *what, int *where)
{
	UNIVERSE_GRID ugrid;
	GRID_TYPE gt;
	int x, y, dist;

	ASSERT( u != NULL );
	ASSERT( c != NULL );
	ASSERT( xoffset >= -1 && xoffset <= 1 );
	ASSERT( yoffset >= -1 && yoffset <= 1 );
	ASSERT( !(xoffset == 0 && yoffset == 0) );
	ASSERT( what != NULL );
	ASSERT( where != NULL );

	x = c->x;
	y = c->y;

	x = x + xoffset;
	y = y + yoffset;
	dist = 1;

	while( (x >= 0) && (x < u->width)
				&& (y >= 0) && (y < u->height) ) {

		gt = Grid_Get(u, x, y, &ugrid);

		if( gt != GT_BLANK ) {
			if( gt == GT_CELL ) {
				if( ugrid.u.cell->organism != c->organism ) {
					*what = VISION_TYPE_CELL;
					*where = dist;
					return;
				}

			} else if( gt == GT_SPORE ) {
				*what = VISION_TYPE_SPORE;
				*where = dist;
				return;

			} else if( gt == GT_ORGANIC ) {
				*what = VISION_TYPE_ORGANIC;
				*where = dist;
				return;

			} else if( gt == GT_BARRIER ) {
				*what = VISION_TYPE_BARRIER;
				*where = dist;
				return;

			} else if( gt == GT_PLAYER ) {
				*what = VISION_TYPE_CELL;
				*where = dist;
				return;

			} else {
				ASSERT(0);
			}
		}

		x = x + xoffset;
		y = y + yoffset;
		dist += 1;
	}

	/*
	 * We hit the hard barrier surrounding the universe.
	 */
	*what = VISION_TYPE_BARRIER;
	*where = dist;
}