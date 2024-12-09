void CevolveView::OnMouseMove(UINT nFlags, CPoint point)
{
	int xdiff, ydiff;
	CDC *dc;

	/*
	 * If the left or right mouse buttons are no
	 * longer clicked, but we are still in a "mode",
	 * we call the appropriate ButtonUp routine.
	 */
	if( m_panning && (nFlags & MK_LBUTTON) == 0 ) {
		OnLButtonUp(nFlags, point);
		CView::OnMouseMove(nFlags, point);
		return;

	} else if( m_drawingBarrier && (nFlags & MK_RBUTTON) == 0 ) {
		OnRButtonUp(nFlags, m_Point2);
		CView::OnMouseMove(nFlags, point);
		return;

	} else if( m_movingOrganism && (nFlags & MK_RBUTTON) == 0 ) {
		OnRButtonUp(nFlags, m_Point2);
		CView::OnMouseMove(nFlags, point);
		return;
	}

	update_status_cursor(point);

	m_Point2 = point;

	if( m_panning ) {
		dc = GetDC();

		xdiff = m_Point1.x - m_Point2.x;
		ydiff = m_Point1.y - m_Point2.y;

		if( xdiff != 0 || ydiff != 0 ) {
			m_zh.pan(xdiff, ydiff);
			Invalidate(true);
		}

		ReleaseDC(dc);

	} else if( m_drawingBarrier ) {
		create_barrier();
	} else if( m_movingOrganism ) {
		draw_organism_outline();
	}

	m_Point1 = point;

	CView::OnMouseMove(nFlags, point);
}