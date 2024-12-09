void CHexEditView::OnHighlightSelect()
{
	FILE_ADDRESS start_addr, end_addr;

	GetSelAddr(start_addr, end_addr);
	if (hl_set_.range_.empty())
	{
		TaskMessageBox("Nothing selected",
			"There is nothing highlighted in this file.  "
			"The closest highlight could not be selected.");
		theApp.mac_error_ = 10;
		return;
	}
	else
	{
		range_set<FILE_ADDRESS>::range_t::const_iterator pp =
			lower_bound(hl_set_.range_.begin(),
						hl_set_.range_.end(),
						range_set<FILE_ADDRESS>::segment(start_addr+1, start_addr+1),
						segment_compare());
		if (pp != hl_set_.range_.begin())
			pp--;
		MoveWithDesc("Select Highlight ", pp->sfirst, pp->slast);
		theApp. SaveToMacro(km_highlight, (unsigned __int64)5);
	}
}