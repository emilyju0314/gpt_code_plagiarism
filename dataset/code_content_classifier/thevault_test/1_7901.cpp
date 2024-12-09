void CevolveView::move_organism()
{
	CevolveDoc* pDoc = GetDocument();
	UNIVERSE *u = pDoc->universe;
	GRID_TYPE gt;
	UNIVERSE_GRID ugrid;
	double fx, fy;
	int x, y;
	int ox, oy;
	int nx, ny;
	ORGANISM *organism;
	CELL *c;
	bool vacant_spot;

	TF_WinToWorld(m_zh.tf, m_Point2.x, m_Point2.y, &fx, &fy);
	x = (int) floor(fx+0.5);
	y = (int) floor(fy+0.5);

	organism = m_move_cell->organism;
	ox = m_move_cell->x;
	oy = m_move_cell->y;

	if( ox == x && oy == y ) {
		Invalidate(true);
		return;
	}

	//
	// Make sure the move is possible
	//
	vacant_spot = true;
	for(c=organism->cells; c != NULL; c=c->next) {
		nx = x + (c->x - ox);
		ny = y + (c->y - oy);

		if( nx < 0 || nx >= u->width ) {
			vacant_spot = false;
			break;
		}

		if( ny < 0 || ny >= u->height ) {
			vacant_spot = false;
			break;
		}

		gt = Universe_Query(u, nx, ny, &ugrid);
		if( gt == GT_BLANK ) {
			//
			// Good.
			//

		} else if( gt == GT_CELL ) {
			//
			// Good, except if cell is not our own
			//
			if( ugrid.u.cell->organism != organism ) {
				vacant_spot = false;
				break;
			}
		} else {
			vacant_spot = false;
			break;
		}
	}

	if( ! vacant_spot ) {
		//
		// User moved the organism to an invalid location.
		//
		Invalidate(true);
		return;
	}

	//
	// Move organism
	//
	for(c=organism->cells; c != NULL; c=c->next) {
		Grid_Clear(u, c->x, c->y);
	}

	for(c=organism->cells; c != NULL; c=c->next) {
		nx = x + (c->x - ox);
		ny = y + (c->y - oy);
		c->x = nx;
		c->y = ny;
		Grid_SetCell(u, c);
	}

	//
	// Redraw the view.
	//
	pDoc->SetModifiedFlag(true);
	Invalidate(true);

}