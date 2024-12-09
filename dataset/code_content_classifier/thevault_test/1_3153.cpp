void CHexEditView::get_colours(std::vector<COLORREF> &kk)
{
	int ii;

	// First find the scheme in app's list of schemes
	std::vector<CScheme>::const_iterator ps;
	for (ps = theApp.scheme_.begin(); ps != theApp.scheme_.end(); ++ps)
		if (ps->name_ == scheme_name_)
			break;

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
	}

	// Default colours to background (ie, init. unspecified colours)
	kk.clear();
	kk.reserve(256);
	kk.resize(256, bg_col_);

	ASSERT(ps->range_val_.size() == ps->range_col_.size());
	for (ii = ps->range_val_.size(); ii > 0; ii--)
	{
		COLORREF colour = (ps->range_col_[ii-1] == -1 ? ::GetSysColor(COLOR_WINDOWTEXT) : ps->range_col_[ii-1]);

		// Set colour for all in this range
		for (range_set<int>::const_iterator rr = ps->range_val_[ii-1].begin(); rr != ps->range_val_[ii-1].end(); ++rr)
		{
			assert(*rr < 256);
			kk[*rr] = colour;
		}
	}
}