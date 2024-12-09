void LoadHist(std::vector<CString> & hh, LPCSTR name, size_t smax)
{
	CString ss, entry;
	CString fmt = CString(name) + "%d";

	hh.clear();
	for (int ii = smax; ii > 0; ii--)
	{
		entry.Format(fmt, ii);
		ss = theApp.GetProfileString("History", entry);
		if (!ss.IsEmpty())
			hh.push_back(ss);
	}
}