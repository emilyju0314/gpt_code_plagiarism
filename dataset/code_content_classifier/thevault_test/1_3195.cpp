void CHexEditView::OnCopyCchar()
{
	num_entered_ = num_del_ = num_bs_ = 0;      // Stop any editing

	// Get the addresses of the selection
	FILE_ADDRESS start, end;
	GetSelAddr(start, end);
	ASSERT(start >= 0 && start <= end && end <= GetDocument()->length());
	if (start == end)
	{
		// Copy to clipboard while nothing selected, presumably in macro playback
		ASSERT(theApp.playing_);
		TaskMessageBox("Nothing selected",
			"This command uses the current selection.  "
			"As there is no selection, nothing was copied.");
		theApp.mac_error_ = 10;
		return;
	}

	int addr_flags = Bin2Src::NONE;
	if (hex_width_ > 0)
		addr_flags |= Bin2Src::HEX_ADDRESS;
	if (dec_width_ > 0)
		addr_flags |= Bin2Src::DEC_ADDRESS;
	if (num_width_ > 0)
		addr_flags |= Bin2Src::LINE_NUM;
	if (display_.addrbase1)
		addr_flags |= Bin2Src::ADDR1;

	CCopyCSrc dlg(GetDocument(), start, end, rowsize_, offset_, addr_flags);
	if (dlg.DoModal() == IDOK)
	{
		do_copy_src(dlg.for_, dlg.type_,
			dlg.type_ == CCopyCSrc::FLOAT ? dlg.float_size_ : dlg.int_size_,
			dlg.int_type_,
			dlg.big_endian_,
			dlg.show_address_,
			dlg.align_cols_,
			dlg.indent_);
	}
}