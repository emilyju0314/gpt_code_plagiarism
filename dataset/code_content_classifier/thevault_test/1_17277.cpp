TrackSend::TrackSend(const char* str, const char* auxvol, const char* auxpan, const char* auxmute)
{
	LineParser lp(false);
	lp.parse(str);
	stringToGuid(lp.gettoken_str(1), &m_destGuid);
	// Strip out the "AUXRECV X" header
	const char* p = strchr(str + 8, ' ') + 1;
	m_str.Set(p);

	m_auxvolstr.Set(auxvol);
	m_auxpanstr.Set(auxpan);
	m_auxmutestr.Set(auxmute);
}