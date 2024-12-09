void CevolveView::OnRButtonDown(UINT nFlags, CPoint point)
{

	//
	// Right click tools don't work if
	// simulator is running.
	//
	if( ! m_stopped )
		return;

	if( get_rca() == RCA_NOTHING ) {
		// do nothing

	} else if( get_rca() == RCA_BARRIER || get_rca() == RCA_THIN_BARRIER ) {
		OnRButtonDown_Barrier(nFlags, point);

	} else if( get_rca() == RCA_DYE ) {
		OnRButtonDown_Dye(nFlags, point);

	} else if( get_rca() == RCA_MOVE ) {
		OnRButtonDown_Move(nFlags, point);

	} else if( get_rca() == RCA_ENERGY ) {
		OnRButtonDown_Energy(nFlags, point);
	}

	CView::OnRButtonDown(nFlags, point);
}