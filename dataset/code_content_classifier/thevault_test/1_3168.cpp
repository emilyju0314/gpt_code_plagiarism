void CHexEditView::get_dffd_in_range(CPointAp &pos)
{
	// Get template fields (address range and background colour) in the display area
	dffd_bg_.clear();
	if (pdfv_ != NULL)
	{
		CRect cli;
		CRectAp rct;
		GetDisplayRect(&cli);
		rct = ConvertFromDP(cli);

		FILE_ADDRESS start, end;            // range of file addresses within display
		start = (pos.y/line_height_)*rowsize_ - offset_;     // First addr in display
		if (start < 0) start = 0;                           // Just in case (prob not nec.)
		end = ((pos.y+rct.Height())/line_height_ + 1)*rowsize_ - offset_;

		GetDocument()->FindDffdEltsIn(start, end, dffd_bg_);
	}
}