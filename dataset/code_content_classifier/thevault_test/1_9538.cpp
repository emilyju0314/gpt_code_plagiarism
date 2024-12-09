void Tool_humsheet::printColSpan(HTp token) {
	if (!token->getOwner()->hasSpines()) {
		m_free_text << " colspan=\"" << m_max_field << "\"";
		return;
	}
	int track = token->getTrack() - 1;
	int scount = m_max_subtrack.at(track);
	int subtrack = token->getSubtrack();
	if (subtrack > 1) {
		subtrack--;
	}
	HTp nexttok = token->getNextFieldToken();
	int ntrack = -1;
	if (nexttok) {
		ntrack = nexttok->getTrack() - 1;
	}
	if ((ntrack < 0) || (ntrack != track)) {
		// at the end of a primary spine, so do a colspan with the remaining subtracks
		if (subtrack < scount-1) {
			int colspan = scount - subtrack;
			m_free_text << " colspan=\"" << colspan << "\"";
		}
	} else {
		// do nothing
	}
}