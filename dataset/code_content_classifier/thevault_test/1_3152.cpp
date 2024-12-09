BOOL CHexEditView::set_colours()
{
	if (scheme_name_.IsEmpty())
		scheme_name_ = theApp.open_scheme_name_;  // Use default

	BOOL retval = TRUE;
	std::vector<CScheme>::const_iterator ps;
	ASSERT(theApp.scheme_.size() > 3);

	// First find the scheme
	for (ps = theApp.scheme_.begin(); ps != theApp.scheme_.end(); ++ps)
	{
		if (ps->name_ == scheme_name_)
			break;
	}

	// If the scheme was not found use the standard one matching selected options
	if (ps == theApp.scheme_.end())
	{
		// Current scheme name is not found so set to something OK and return error
		if (display_.char_set == CHARSET_EBCDIC)
			ps = theApp.scheme_.begin()+3;
		else if (display_.char_set == CHARSET_OEM)
			ps = theApp.scheme_.begin()+2;
		else if (display_.char_set == CHARSET_ANSI)
			ps = theApp.scheme_.begin()+1;
		else
			ps = theApp.scheme_.begin();
		scheme_name_ = ps->name_;
		retval = FALSE;
	}

	// Get colours from scheme, where -1 means use default (Automatic) colour
	bg_col_        = ps->bg_col_ == -1       ? ::GetSysColor(COLOR_WINDOW) : ps->bg_col_;
	mark_col_      = ps->mark_col_ == -1     ? RGB(224, 224, 224) : ps->mark_col_;
	hi_col_        = ps->hi_col_ == -1       ? RGB(255, 255, 0) : ps->hi_col_;              // yellow
	bm_col_        = ps->bm_col_ == -1       ? RGB(160, 192, 255) : ps->bm_col_;
	search_col_    = ps->search_col_ == -1   ? RGB(160, 255, 224) : ps->search_col_;
	addr_bg_col_   = ps->addr_bg_col_ == -1  ? ::tone_down(::GetSysColor(COLOR_INACTIVEBORDER), bg_col_, 0.5) : ps->addr_bg_col_;
	// Getting change tracking colour and make a version closer to the background colour in luminance
	// trk_col_ is used to underline replacements, trk_bg_col_ is used as background for insertions
	trk_col_ = ps->trk_col_ == -1 ? RGB(255, 128, 0) : ps->trk_col_;              // default change tracking colour is orange-red
	trk_bg_col_    = ::tone_down(trk_col_, bg_col_);
	comp_col_ = ps->comp_col_ == -1 ? RGB(255, 0, 255) : ps->comp_col_;           // default compare tracking colour = purple
	comp_bg_col_   = ::tone_down(comp_col_, bg_col_);

	sector_col_    = ps->sector_col_ == -1   ? RGB(255, 160, 128)   : ps->sector_col_;          // pinkish orange
	sector_bg_col_ = ::tone_down(sector_col_, bg_col_);
	hex_addr_col_  = ps->hex_addr_col_ == -1 ? ::GetSysColor(COLOR_WINDOWTEXT) : ps->hex_addr_col_;
	dec_addr_col_  = ps->dec_addr_col_ == -1 ? ::GetSysColor(COLOR_WINDOWTEXT) : ps->dec_addr_col_;

	// Set the default text colour (used for text not specific to a range)
	if (ps->range_col_.size() > CColourSchemes::INDEX_LAST)
		text_col_ = ps->range_col_[CColourSchemes::INDEX_LAST]; // was back()
	else
		text_col_ = ::GetSysColor(COLOR_WINDOWTEXT);  // no ranges at all so use windows default

	int ii;

	// Default colours to background (makes unspecified colours invisible)
	for (ii = 0; ii < 256; ++ii)
		kala[ii] = bg_col_;

	ASSERT(ps->range_val_.size() == ps->range_col_.size());
	for (ii = ps->range_val_.size(); ii > 0; ii--)
	{
		COLORREF colour = (ps->range_col_[ii-1] == -1 ? ::GetSysColor(COLOR_WINDOWTEXT) : ps->range_col_[ii-1]);

		// Set colour for all in this range
		for (range_set<int>::const_iterator rr = ps->range_val_[ii-1].begin(); rr != ps->range_val_[ii-1].end(); ++rr)
		{
			kala[*rr] = add_contrast(colour, bg_col_);
		}
	}

	// Keep data format view colours in sync
	if (pdfv_ != NULL)
	{
		ASSERT_KINDOF(CDataFormatView, pdfv_);
		pdfv_->set_colours();
	}

	if (pav_ != NULL)
	{
		ASSERT_KINDOF(CAerialView, pav_);
		GetDocument()->AerialChange(this);
	}

	return retval;
}