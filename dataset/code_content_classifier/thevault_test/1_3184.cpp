int CHexEditView::bookmark_at(FILE_ADDRESS addr)
{
	std::vector<FILE_ADDRESS>::const_iterator pp =
		std::find(GetDocument()->bm_posn_.begin(), GetDocument()->bm_posn_.end(), addr);
	if (pp != GetDocument()->bm_posn_.end())
		return pp - GetDocument()->bm_posn_.begin();
	else
		return -1;
}