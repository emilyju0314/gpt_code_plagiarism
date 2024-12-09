void CevolveView::draw_organism_outline()
{
	ORGANISM *organism;
	CELL *c;
	int x, y;
	int ox, oy;
	int nx, ny;
	TF_RECT ugworld, ugwin;
	CRect rect;
	CDC *dc;
	double fx, fy;
	int pOldROP2;
	CGdiObject *pOldBrush;
	CPen *pOldPen;

	dc = GetDC();

	pOldBrush = dc->SelectStockObject(HOLLOW_BRUSH);
	pOldPen = dc->SelectObject(&m_appearance.dyePen);
	pOldROP2 = dc->SetROP2(R2_XORPEN);

	ox = m_move_cell->x;
	oy = m_move_cell->y;

	//
	// First erase previous outline at point m_Point1
	//
	TF_WinToWorld(m_zh.tf, m_Point1.x, m_Point1.y, &fx, &fy);
	x = (int) floor(fx+0.5);
	y = (int) floor(fy+0.5);

	organism = m_move_cell->organism;
	for(c=organism->cells; c != NULL; c=c->next) {
		nx = x + (c->x - ox);
		ny = y + (c->y - oy);

		ugworld.left	= nx - 0.5;
		ugworld.top	= ny - 0.5;
		ugworld.right	= nx + 0.5;
		ugworld.bottom	= ny + 0.5;

		TF_WorldToWin(m_zh.tf, ugworld.left, ugworld.top,
				&ugwin.left, &ugwin.top);

		TF_WorldToWin(m_zh.tf, ugworld.right, ugworld.bottom,
				&ugwin.right, &ugwin.bottom);

		rect.left	= (int) ugwin.left;
		rect.top	= (int) ugwin.top;
		rect.right	= (int) ugwin.right;
		rect.bottom	= (int) ugwin.bottom;

		//
		// This ensures that we draw somthing, even at very
		// tiny scales.
		//
		if( rect.right - rect.left <= 1
				|| rect.bottom - rect.top <= 1 ) {
			rect.right += 1;
			rect.bottom += 1;
		}

		dc->Rectangle(rect);
	}

	//
	// Draw new outlin at point m_Point2
	//
	TF_WinToWorld(m_zh.tf, m_Point2.x, m_Point2.y, &fx, &fy);
	x = (int) floor(fx+0.5);
	y = (int) floor(fy+0.5);

	organism = m_move_cell->organism;
	for(c=organism->cells; c != NULL; c=c->next) {
		nx = x + (c->x - ox);
		ny = y + (c->y - oy);

		ugworld.left	= nx - 0.5;
		ugworld.top	= ny - 0.5;
		ugworld.right	= nx + 0.5;
		ugworld.bottom	= ny + 0.5;

		TF_WorldToWin(m_zh.tf, ugworld.left, ugworld.top,
				&ugwin.left, &ugwin.top);

		TF_WorldToWin(m_zh.tf, ugworld.right, ugworld.bottom,
				&ugwin.right, &ugwin.bottom);

		rect.left	= (int) ugwin.left;
		rect.top	= (int) ugwin.top;
		rect.right	= (int) ugwin.right;
		rect.bottom	= (int) ugwin.bottom;

		//
		// This ensures that we draw somthing, even at very
		// tiny scales.
		//
		if( rect.right - rect.left <= 1
				|| rect.bottom - rect.top <= 1 ) {
			rect.right += 1;
			rect.bottom += 1;
		}

		dc->Rectangle(rect);
	}

	dc->SelectObject(pOldBrush);
	dc->SelectObject(pOldPen);
	dc->SetROP2(pOldROP2);

	ReleaseDC(dc);
}