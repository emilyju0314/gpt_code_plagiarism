int CHexEditView::ClosestBookmark(FILE_ADDRESS &diff)
{
	std::vector<FILE_ADDRESS>::const_iterator prev_bm = GetDocument()->bm_posn_.end();
	diff = GetDocument()->length()+1;  // Bigger than any possible difference between current & bookmark
	FILE_ADDRESS start_addr, end_addr;

	GetSelAddr(start_addr, end_addr);

	// Find the bookmark that is closest but after the current address
	for (std::vector<FILE_ADDRESS>::const_iterator pbm = GetDocument()->bm_posn_.begin();
		 pbm != GetDocument()->bm_posn_.end(); ++pbm)
	{
		if (*pbm <= start_addr && start_addr - *pbm < diff)
		{
			diff = start_addr - *pbm;
			prev_bm = pbm;
		}
	}
	if (prev_bm == GetDocument()->bm_posn_.end())
		return -1;
	else
		return GetDocument()->bm_index_[prev_bm - GetDocument()->bm_posn_.begin()];
}