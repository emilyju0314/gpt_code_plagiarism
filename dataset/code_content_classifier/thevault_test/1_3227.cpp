CString FormatDate(DATE dd)
{
	// First get the short date format from Windows Control Panel Region Settings
	CString fmt;
	UDATE ud;                              // unpacked date
	_locale_t ploc = _get_current_locale();
	plocal_time_info_t plti = (plocal_time_info_t)ploc->locinfo->lc_time_curr;
	fmt = CString(plti->ww_sdatefmt);
	char buf[80];

	// If format does not have 4 digit year (yyyy) convert 2 digit year to 4 digit year
	if (fmt.Find("yyyy") == -1 &&
		fmt.Replace("yy", "yyyy") > 0)
	{
		if (::VarUdateFromDate(dd, 0, &ud) == S_OK && 
			::GetDateFormat(LOCALE_USER_DEFAULT, 0, &ud.st, fmt, buf, sizeof(buf)) > 0)
		{
			return CString(buf);
		}
		else
		{
			return CString("Invalid Date");
		}
	}

	// Fall back on MS code
	COleDateTime odt;
	odt.m_dt = dd;
	odt.m_status = COleDateTime::valid;
	return odt.Format("%x");
}