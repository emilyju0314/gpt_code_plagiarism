void CevolveView::OnLButtonUp(UINT nFlags, CPoint point)
{
	CDC *dc;

	if( ! m_panning )
		return;

	m_panning = false;

	m_Point2 = point;

	dc = GetDC();

	if( m_Point0 == m_Point2 ) {
		CevolveDoc* pDoc = GetDocument();
		UNIVERSE *u;
		UNIVERSE_GRID ugrid;
		GRID_TYPE type;
		double fx, fy;
		int x, y;

		TF_WinToWorld(m_zh.tf, point.x, point.y, &fx, &fy);
		x = (int) floor(fx+0.5);
		y = (int) floor(fy+0.5);

		u = pDoc->universe;

		if( x >= 0 && x < u->width && y >= 0 && y < u->height ) {
			type = Universe_Query(u, x, y, &ugrid);
			if( type == GT_CELL ) {
				Universe_SelectOrganism(u, ugrid.u.cell->organism);
				Invalidate(true);
			} else {
				Universe_ClearSelectedOrganism(u);
				Invalidate(true);
			}
		}
	}

	CView::OnLButtonUp(nFlags, point);

	ReleaseDC(dc);
}