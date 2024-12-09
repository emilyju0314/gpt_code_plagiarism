int CAerialView::elt_at(CPoint pt)
{
	// First make sure it is within the display area
	if (pt.x < bdr_left_ || pt.x >= cols_ * actual_dpix_ + bdr_left_ || 
		pt.y < bdr_top_  || pt.y >= rows_ * actual_dpix_ + bdr_top_)
	{
		return -1;
	}

	// Convert to elt coords
	pt.x = (pt.x - bdr_left_)/actual_dpix_;
	pt.y = (pt.y - bdr_top_)/actual_dpix_;


	// Work out absolute elt in the file
	int elt = int(scrollpos_/GetDocument()->GetBpe()) + pt.y * cols_ + pt.x;
	if (elt < 0)
		elt = 0;
	else if (elt > GetDocument()->NumElts())
		elt = GetDocument()->NumElts();
	return elt;
}