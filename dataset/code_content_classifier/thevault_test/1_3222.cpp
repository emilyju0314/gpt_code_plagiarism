void SaveHist(std::vector<CString> const & hh, LPCSTR name, size_t smax)
{
	CString entry;
	CString fmt = CString(name) + "%d";

	int ii, num = min(hh.size(), smax);

	// Write th new entries
	for (ii = 1; ii <= num; ++ii)
	{
		// Check that we don't write any empty strings as this will cause problems
		ASSERT(!hh[hh.size()-ii].IsEmpty());

		entry.Format(fmt, ii);
		theApp.WriteProfileString("History", entry, hh[hh.size()-ii]);
	}
	// Wipe out any old entries past the new end
	for ( ; ; ++ii)
	{
		entry.Format(fmt, ii);

		// Stop when there are no more entries in the registry to be blanked out.
		if (theApp.GetProfileString("History", entry).IsEmpty())
			break;

		theApp.WriteProfileString("History", entry, NULL);
	}
}